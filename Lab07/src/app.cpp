#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <Array.h>
#include <LinkedList.h>
#include <TimeSupport.h>
#include <RandomSupport.h>
#include <BST.h>

/*
  words.txt: 5778 words, 434 ms
  words2.txt: 756 words, 34 ms
  words3.txt: 14 words, 0 ms
My results:
  words.txt: too long - over 15 mins
  words2.txt: 756 words, 40000 ms - 44000 ms
  words3.txt: 14 words, 0 ms
*/

using namespace std;

const long N = pow(128, 3);
ResizableArray words;
LinkedList* table = new LinkedList[N];
long i = 0;

// Hash func to convert string to integer
long f(string s) {
  // while loop will run if word has less than 4 chars and will add a space
  // until word reaches 4 chars
  while (s.length() < 4) {
    s += " ";
  }
  return (s[0] * pow(128, 4)) + (s[1] * pow(128, 3)) + (s[2] * pow(128, 2)) + (s[3] * pow(128, 1));
}

string reverses(string word){
  reverse(word.begin(), word.end());
  return word;
}

bool find(string word, ResizableArray& arr) {
  for (long i = 0; i < arr.count; i++) {
    if (word == arr[i]) {
      return true;
    }
  }
  return false;
}



void insert(string word, LinkedList* ht) {
  long index = f(word);
  ht[index].append(word);
}

bool search( string word, LinkedList* ht) {
  long index = f(word);
  return ht->search(word);

}

int main() {
  fstream file;     
  string tp;

  file.open("words2.txt", ios::in);

  long count = 0;
  if (file.is_open()) {

    while(getline(file, tp)){
      table->append(tp);
      insert(tp, table);
      words.append(tp);
    }
    file.close(); 
  }
  else{
    cout << "Could not read file..." << endl;
  }

  timestamp start = current_time();

  long word_count = 0;
  for (long i = 0; i <= words.count; i++) {
    string rev = reverses(words[i]);
    // if (reverses(words[i]) == (words[i])) {
      if (find(rev, words)) {
        //cout << words[i] << endl;
        word_count++;
      }
    // }
  }

  timestamp end = current_time();
  long diff = time_diff(start, end);

  cout << "Found " << word_count << " words." << endl;
  cout << "Done in " << diff << " ms." << endl;

}
