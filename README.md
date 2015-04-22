## CSE223B Lab2 README

### BinStorage Design 

#### BinStorage entry function:
In the top to down order, the `NewBinClient()` function will return a `binClient` struct and implement BinStorage interface `Bin`. This `Bin` function will return a `clientBin` struct, which implement the Storage interface. The address of backend server for this `clientBin` is the value of hashing BinName, which I set to exactly the username. The `NewFront()` function will return the `binClient`, which can call all the frontend server method. `ServeKeeper()` is just an start an keeper, which can periodically scan different servers and call the `Clock()` RPC. Feed the previous server's updated clock value to the atLeast parameter for the next server. 

#### Bin Key Value design:
Any key from certain user will be add a prefix of its username. There are three kinds of keys: Follow, Post, Users. 
The previous two are binded to certain user. Therefore, after `clientBin` call RPC function, the key becomes `username:Follow/Post`. The key "User" is slightly different. I stored it with BinName of empty string "". This User list also is just an dummy list, which has only 20 user at most. For other users' quick check, I store an <key, value> pair `<"Exist", "True">` at every signed up user's Bin. If the value of "Exist" return from user's own bin is empty, then it means this user do not signed up before, and vice versa. 

### Tribbler Design

The important part for tribbler is design the key and corresponding value. 
The value for Post in string format is as follows:
```who : clock : colo.Escape(timestamp) : message ```
Because who and clock can never have ":" in it and using escape can remove all the possible ":" in it, thus ":" can be a good delimiter to retrieve every part of post later. 

Garbage collection is also done inside of `Post()`. Everytime the user want to post one tribble, it will first append this tribble to its `Post` list, then remove the part of oldest tribbles when there are more than trib.MaxTribFetch. If server get failed before the remove operation is also acceptable to maintain a slightly larger list. It can be deleted by later success post operation. 

The `Follow` and `Unfollow` part are all dealing with `username:Follow` list, which are append and remove value from this list. The concurrency problem is discussed below

The `Home` or `Tribs` operation just sort the tribbles either include its followers or not. And present the most updated one. 

### Concurrency Design

The concurrency problem may happen when more than one frontend server from one user follow or unfollow the same user, and only allows one user returns without error. The solution for this create a special list in a global bin. Then every user "who" want to follow certain other user "whom" will append a <key, value> pair `<who+whom, clock>`. The clock value is monotonically increasing because I will call the PRC `Clock()` before I append pair. After that, we only allow the user who set the first entry in this list to get pass. All concurrent user will continue wait and fetch this list and check whether it is in the first place of this list. Another timeout mechanism is added to this, after a certain period of time, any user can remove the first entry. This is to avoid some user failed and everyone else will looping forever. With this guarantee in the `Follow` operation, the `Unfollow` just to check whether it can remove exactly one key value pair. All the concurrent `Unfollow` client should only one user remove exact one entry. 




