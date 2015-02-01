/* This function is used for binary search
Return value:
Not found : -1
Matched found: index of found element
*/

int twoSumBS(vector<int> &numbers, int match, int& front, int& back) {
    int mid;
    while (front <= back) {
    mid = (front + back)/2;
        if (numbers[mid] > match)
            back = mid - 1;    // division is roundDown fashion
        else if (numbers[mid] == match)
            return mid;
        else
            front = mid + 1;
    }
    return -1;
}
