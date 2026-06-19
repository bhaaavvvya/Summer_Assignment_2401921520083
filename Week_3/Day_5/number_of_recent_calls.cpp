//adding required header files
#include<iostream>
#include<queue>
using namespace std;

//APPROACH:
//Store all ping times in a queue.
//
//For every new ping,
//insert the current time into the queue.
//
//Remove all times that are older than
//t - 3000 since they are outside
//the valid range [t - 3000, t].
//
//The remaining queue size represents
//the number of recent requests.
//Time complexity: O(1) amortized
//Space complexity: O(N)

class RecentCounter
{
public:
    queue<int> q;

    RecentCounter()
    {
    }

    int ping(int t)
    {
        q.push(t);

        while(q.front() < t - 3000)
            q.pop();

        return q.size();
    }
};

int main()
{
    RecentCounter rc;
    cout << rc.ping(1) << endl;
    cout << rc.ping(100) << endl;
    cout << rc.ping(3001) << endl;
    cout << rc.ping(3002) << endl;
    return 0;
}