#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*
class Solution
{
public:
    vector<int> topStudents(vector<string> &positive_feedback,
                            vector<string> &negative_feedback,
                            vector<string> &report, vector<int> &student_id,
                            int k)
    {
        vector<int> ans;
        // unordered_map<int, int> m;
        // Define a priority queue that sorts pairs of (count, id)
        // Use a custom comparator to sort in descending order of count,
        // and in ascending order of id if counts are the same.
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b)
        {
            if (a.first == b.first)
            {
                return a.second >
                       b.second; // Lower id comes first if counts are equal
            }
            return a.first < b.first; // Higher count comes first
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
            pq(cmp);

        for (int i = 0; i < report.size(); i++)
        {
            stringstream ss(report[i]);
            string word;
            int cnt = 0;

            // Split the sentence into words
            while (ss >> word)
            {
                // Check if word present in positive
                if (std::find(positive_feedback.begin(),
                              positive_feedback.end(),
                              word) != positive_feedback.end())
                {
                    cnt += 3;
                }
                else if (std::find(negative_feedback.begin(),
                                   negative_feedback.end(),
                                   word) != negative_feedback.end())
                {
                    cnt -= 1;
                }
                else
                    continue;
            }

            // inserting in map
            pq.push({cnt, student_id[i]});
        }

        // pop and push top to vector
        while (!pq.empty() && k != 0)
        {
            ans.push_back(pq.top().second);
            // cout << "ID: " << pq.top().second << ", Count: " <<
            // pq.top().first << endl;
            pq.pop();
            k--;
        }
        return ans;
    }
};
*/

class Solution
{
public:
    vector<int> topStudents(vector<string> &positive_feedback,
                            vector<string> &negative_feedback,
                            vector<string> &report, vector<int> &student_id,
                            int k)
    {
        vector<int> ans;

        // Use unordered_set for O(1) lookups
        unordered_set<string> posSet(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> negSet(negative_feedback.begin(), negative_feedback.end());

        // Vector to hold (count, student_id) pairs
        vector<pair<int, int>> scores;

        for (int i = 0; i < report.size(); i++)
        {
            stringstream ss(report[i]);
            string word;
            int cnt = 0;

            // Split the sentence into words
            while (ss >> word)
            {
                // Check if word present in positive
                if (posSet.count(word))
                {
                    cnt += 3;
                }
                else if (negSet.count(word))
                {
                    cnt -= 1;
                }
            }

            // Store the score and student ID
            scores.push_back({cnt, student_id[i]});
        }

        // Sort the scores vector
        sort(scores.begin(), scores.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 if (a.first == b.first)
                 {
                     return a.second < b.second; // Lower id comes first if counts are equal
                 }
                 return a.first > b.first; // Higher count comes first
             });

        // Collect the top k student IDs
        for (int i = 0; i < k && i < scores.size(); i++)
        {
            ans.push_back(scores[i].second);
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    // Test Case 1
    vector<string> positive_feedback1 = {"good", "excellent", "well"};
    vector<string> negative_feedback1 = {"bad", "poor", "terrible"};
    vector<string> report1 = {"good excellent well", "poor terrible", "good poor well"};
    vector<int> student_id1 = {101, 102, 103};
    int k1 = 2;
    vector<int> result1 = sol.topStudents(positive_feedback1, negative_feedback1, report1, student_id1, k1);
    cout << "Test Case 1: ";
    for (int id : result1)
    {
        cout << id << " ";
    }
    cout << endl;

    // Test Case 2
    vector<string> positive_feedback2 = {"smart", "brilliant", "amazing"};
    vector<string> negative_feedback2 = {"lazy", "dull", "weak"};
    vector<string> report2 = {"smart brilliant", "lazy dull", "amazing smart"};
    vector<int> student_id2 = {201, 202, 203};
    int k2 = 3;
    vector<int> result2 = sol.topStudents(positive_feedback2, negative_feedback2, report2, student_id2, k2);
    cout << "Test Case 2: ";
    for (int id : result2)
    {
        cout << id << " ";
    }
    cout << endl;

    // Test Case 3
    vector<string> positive_feedback3 = {"hardworking", "diligent", "focused"};
    vector<string> negative_feedback3 = {"careless", "negligent", "sloppy"};
    vector<string> report3 = {"hardworking focused", "diligent careless", "focused sloppy"};
    vector<int> student_id3 = {301, 302, 303};
    int k3 = 1;
    vector<int> result3 = sol.topStudents(positive_feedback3, negative_feedback3, report3, student_id3, k3);
    cout << "Test Case 3: ";
    for (int id : result3)
    {
        cout << id << " ";
    }
    cout << endl;

    return 0;
}
