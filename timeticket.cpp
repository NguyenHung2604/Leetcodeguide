#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// Solution 1: Use a queue

int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> queue;

        // Initialize the queue with ticket indices
        for (int i = 0; i < tickets.size(); i++) {
            queue.push(i);
        }

        int time = 0;

        // Loop until the queue is empty
        while (!queue.empty()) {
            // Increment the time counter for each iteration
            time++;

            // Get the front element of the queue
            int front = queue.front();
            queue.pop();

            // Buy a ticket for the front person
            tickets[front]--;

            // If person k bought all their tickets, return time
            if (k == front && tickets[front] == 0) {
                return time;
            }

           // Re-add the current index to the queue for the next iteration if there are still tickets
            if (tickets[front] != 0) {
                queue.push(front);
            }
        }

        return time;
    }

// Solution 2: Use a nested loop
int timeRequiredToBuy(vector<int>& tickets, int k) 
    {
        int n = tickets.size();
        int time = 0;

        if(tickets[k] == 1)
        {
            return k + 1;
        }

        while(tickets[k] != 0)
        {
            for(int i = 0; i < n; i++)
            {
                if(tickets[i] != 0)
                {
                    tickets[i] --;
                    time++;
                }

                if(tickets[k] == 0) return time;
    
            }

        }
        return time;
    }
// solution 3: Optimize, implement with 1 pass

int timeRequiredToBuy(vector<int>& tickets, int k) 
{
    int time = 0;
    
    for(int i = 0; i < tickets.size(); i++)
    {
        if(i <= k)
        {
            time += min(tickets[k], tickets[i]);
        }
        else
        {
            time += min(tickets[k] - 1, tickets[i]);
        }
    }

    return time;
}




