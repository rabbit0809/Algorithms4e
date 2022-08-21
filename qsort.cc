#include <iterator>

template <typename CONTAINER>
void qsort(CONTAINER &arr, int beg, int end) {
  if (beg > end) {
    return;
  }
  int pivot = arr[beg];
  int slot = beg;
  for (auto i = beg+1; i <= end; i++) {
    if (arr[i] <= pivot) {
      // TPT: We never overrun the end of the array.
      // beg is always valid
      // We're at an entry after the current slot. Enforced because:
      // Slot is always behind the current iterator. Could make this explicit by?
      // slot + num after?
      arr[slot] = arr[i];
      slot++;
      arr[i] = arr[slot];
    }
  }
  arr[slot] = pivot;
  qsort(arr, beg, slot - 1);
  qsort(arr, slot + 1, end);
}
