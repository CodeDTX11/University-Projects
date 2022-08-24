/*
    Author: Dylan Messerly

*/

#include <iostream>
#include <random>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>

using namespace std;

const int MAX = 20;
const int PAGE = 5;

int LRU(int ref_string[], int frames);
int Optimal(int ref_string[], int frames);


int main ( ) {
    int reference_string[MAX];

    int frames;
    int LRUfaults, OPTfaults;

    unsigned seed = time(0);
    srand(seed);

    for (int i = 0;i < MAX; i++)
        reference_string[i] = rand() % PAGE + 1;

    cout << "Reference string: ";
    for (int i = 0;i < MAX; i++)
        cout << reference_string[i] << " ";


    cout << "\nEnter desired number of frames: ";
    cin >> frames;

    cout << "\nLRU PROCESS: " << endl;
    LRUfaults = LRU(reference_string, frames);

    cout << "\nOPTIMAL PROCESS: " << endl;
    OPTfaults = Optimal(reference_string, frames);

    cout << "\n# of LRU faults: " << LRUfaults << endl;

    cout << "# of Optimal faults: " << OPTfaults << endl;


    return 0;
}


int LRU(int ref_string[], int frames){

    unordered_set<int> set;
    unordered_map<int, int> indexes;

    int page_faults = 0;

    for (int i=0; i<MAX; i++)
    {
        cout << "\nReferencing page " << ref_string[i] << endl;

        if(set.find(ref_string[i])!=set.end())
        {
            cout<<"Reference to page "<< ref_string[i] <<" did not cause a page fault\n";
        }
        else
        {
            if (set.size() < frames)
            {
                set.insert(ref_string[i]);
                page_faults++;
            }
            else
            {
                int lru = INT_MAX, val;
                for (auto it : set)
                {
                    if (indexes[it] < lru)
                    {
                        lru = indexes[it];
                        val = it;
                    }
                }
                set.erase(val);
                set.insert(ref_string[i]);
                page_faults++;
            }
            cout<<"Reference to page "<< ref_string[i] <<" caused a page fault\n";

        }
        indexes[ref_string[i]] = i;

        cout << "Curent frame < ";
        for (auto it : set)
            cout << it << " ";
        cout << ">" << endl;
    }

    return page_faults;
}

int Optimal(int ref_string[], int frames){

    vector<int> frame;
    int page_faults = 0;

    for (int i = 0; i < MAX; i++)
    {
        cout << "\nReferencing page " << ref_string[i] << endl;

        int k;
        for (k = 0; k < frame.size(); k++)
            if (frame[k] == ref_string[i])
                break;

        if (k==frame.size())
        {
            if (frame.size() < frames)
                frame.push_back(ref_string[i]);

            else
            {
                int index=i+1;
                int res = -1, farthest = index;
                for (int l = 0; l < frame.size(); l++)
                {
                    int j;
                    for (j = index; j < MAX; j++)
                    {
                        if (frame[l] == ref_string[j])
                        {
                            if (j > farthest)
                            {
                                farthest = j;
                                res = l;
                            }
                            break;
                        }
                    }
                    if (j == MAX)
                    {
                        res=l;
                        break;
                    }
                }
                frame[res] = ref_string[i];
            }
            page_faults++;
            cout<<"Reference to page "<<ref_string[i]<<" caused a page fault\n";
        }
        else
        {
            cout<<"Reference to page "<<ref_string[i]<<" did not cause a page fault\n";
        }

        cout << "Current frame: " << endl << "< ";
        for(int z = 0; z < frame.size(); z++)
            cout << frame[z] << " ";
        cout << ">" << endl;
    }

    return page_faults;
}

