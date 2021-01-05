#include <iostream>
#include <Array.h>
#include <LinkedList.h>
#include "TimeSupport.h"
#include "RandomSupport.h"

using namespace std;

int main() {
  // Your code here...



  // arr.append (2);
  // arr.append (40);
  // arr.append (912);
  // arr.append (18);
  // arr.append (2);
  // arr.append (40);
  // arr.append (912);
  // arr.append (40);
  // arr.append (912);

  // arr.print ();

  // cout << "Size:      " << arr.size << endl;

  // // Task 1
  // ResizableArray arr;

  // randomizer t1device = new_randomizer();
// uniform_distribution t1dist = new_distribution(1, 30000000);

// long t1 = sample(t1dist, t1device);

  // for (int i = 0; i < t1; i++) {
  //     arr.append (i);
  // }

  // timestamp t1start = current_time ();

  // arr.get (t1);
  // cout << t1 << endl;

  // timestamp t1end = current_time ();
  // long t1time = time_diff (t1start, t1end);
  // cout << "t1: Completed in " << t1time << " ms. " << endl;


  // // Task 2
  // LinkedList list;

  // randomizer t2device = new_randomizer();
// uniform_distribution t2dist = new_distribution(1, 30000000);

// long t2 = sample(t2dist, t2device);

  // for (int i = 0; i < t2; i++) {
  //     list.append (i);
  // }

  // timestamp t2start = current_time ();

  // list.get (t2);
  // cout << t2 << endl;

  // timestamp t2end = current_time ();
  // long t2time = time_diff (t2start, t2end);
  // cout << "t2: Completed in " << t2time << " ms. " << endl;


  // // Task 3
  // ResizableArray arr2;

  // for (int i = 0; i < 30000000; i++) {
  //     arr2.append (i);
  // }

  // timestamp t3start = current_time ();

  // arr2.append (1);

  // timestamp t3end = current_time ();
  // long t3time = time_diff (t3start, t3end);
  // cout << "t3: Completed in " << t3time << " ms. " << endl;


  // // Task 4
  // ResizableArray arr3;

  // for (int i = 0; i < 30000000; i++) {
  //     arr3.append (i);
  // }

  // timestamp t4start = current_time ();

  // arr3.insert (0, 1);

  // timestamp t4end = current_time ();
  // long t4time = time_diff (t4start, t4end);
  // cout << "t4: Completed in " << t4time << " ms. " << endl;


  // // Task 5
  // LinkedList list2;

  // for (int i = 0; i < 30000000; i++) {
  //     list2.append (i);
  // }

  // timestamp t5start = current_time ();

  // list2.append (1);

  // timestamp t5end = current_time ();
  // long t5time = time_diff (t5start, t5end);
  // cout << "t5: Completed in " << t5time << " ms." << endl;


  // // Task 6
  // LinkedList list3;

  // for (int i = 0; i < 30000000; i++) {
  //     list3.append (i);
  // }

  // timestamp t6start = current_time ();

  // list3.prepend (1);

  // timestamp t6end = current_time ();
  // long t6time = time_diff (t6start, t6end);
  // cout << "t6: Completed in " << t6time << " ms." << endl;


  // Programming Task
  ResizableArray arrf;
  LinkedList listf;

  randomizer devicef = new_randomizer();
  uniform_distribution distf = new_distribution(1, 10000);

  long rng = sample(distf, devicef);

  timestamp startf = current_time();

  // loop to create array
  for (int i = 0; i < rng; i++) {
    arrf.insert(0, i);
  }

  timestamp endf = current_time();
  long timef = time_diff(startf, endf);
  cout << "Array took " << timef << " ms. to be completed " << endl;

  startf = current_time();

  // loop to create list
  for (int i = 0; i < rng; i++) {
    listf.prepend(i);
  }

  endf = current_time();
  timef = time_diff(startf, endf);
  cout << "LinkedList took " << timef << " ms. to be completed " << endl;

  return 0;
}
