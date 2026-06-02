//adding required header files
#include<iostream>
#include<vector>
using namespace std;

//APPROACH:
//We will traverse the array while tracking the minimum price seen so far.
//At each day, we calculate profit if we were to sell on that day.
//We update maxProfit if current profit is better.
//We update minCost if current price is lower than the minimum seen so far.

//Time complexity: O(N) (Single pass through the array)
//Space complexity: O(1) (Only two extra variables used)

int maxProfit(vector<int>& prices)
{
    //initialise minimum cost to first day's price
    int minCost = prices[0];
    //initialise maximum profit to 0 (no transaction case)
    int maxProfit = 0;

    for(int i = 1; i < prices.size(); i++)
    {
        //calculate profit if we sell on day i
        int profit = prices[i] - minCost;

        //update maxProfit if we found a better profit
        if(profit > maxProfit)
            maxProfit = profit;

        //update minCost if we found a cheaper buying day
        if(prices[i] < minCost)
            minCost = prices[i];
    }
    //return the maximum profit achievable
    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);
    return 0;
}