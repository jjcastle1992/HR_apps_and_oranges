#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countApplesAndOranges' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER s
 *  2. INTEGER t
 *  3. INTEGER a
 *  4. INTEGER b
 *  5. INTEGER_ARRAY apples
 *  6. INTEGER_ARRAY oranges
 */

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    int leftHouseEdge = s;
    int rightHouseEdge = t;
    int appleTreePos = a;
    int orangeTreePos = b;
    int orangePosition = 0;
    int applePosition = 0;
    int appleHits = 0;
    int orangeHits = 0;
    //Determine where Apple Tree is (left "bound" - though apples can fall left of the tree)
    //Determine where Orange Tree is (right "bound" - though oranges can fall to the right of the tree
    //Determine left edge of house && right edge of house
    
    //check positions of Apples relative to tree
    for (int i = 0; i < apples.size(); i++) {
        int appleDistance = 0;
        appleDistance = apples [i];
        applePosition = appleTreePos - appleDistance;

        //If position of apple  greater/equal to left edge or less than/equal to right edge, it hits.
        //check position of apple and if it falls in the range, increment apple hit counter
        if (applePosition >= leftHouseEdge && applePosition <= rightHouseEdge) {
            appleHits++;
        }
    }

    //check positions of oranges relative to tree
    for (int i = 0; i < oranges.size(); i++) {
        int orangeDistance = 0;
        orangeDistance = oranges [i];
        orangePosition = orangeTreePos - orangeDistance;

        //If position of orange is greater/equal to left edge or less than/equal to right edge, it hits.
        //check position of orange if it falls in the range, increment orange hit counter
        if (orangePosition >= leftHouseEdge && orangePosition <= rightHouseEdge) {
            orangeHits++;
        }
    }

    //print #apple hits then # orange hits each on their own line.
    std::cout << appleHits << std::endl;
    std::cout << orangeHits << std::endl;
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int s = stoi(first_multiple_input[0]);

    int t = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int a = stoi(second_multiple_input[0]);

    int b = stoi(second_multiple_input[1]);

    string third_multiple_input_temp;
    getline(cin, third_multiple_input_temp);

    vector<string> third_multiple_input = split(rtrim(third_multiple_input_temp));

    int m = stoi(third_multiple_input[0]);

    int n = stoi(third_multiple_input[1]);

    string apples_temp_temp;
    getline(cin, apples_temp_temp);

    vector<string> apples_temp = split(rtrim(apples_temp_temp));
    if ((s >= 1 && s <= 1e5) && (t >= 1 && t <= 1e5) && (a >= 1 && a <= 1e5) && (b >= 1 && b <= 1e5)
        && (m >= 1 && m <= 1e5) && (n >= 1 && n <= 1e5) && (a < s < t < b)) {
        vector<int> apples(m);

        for (int i = 0; i < m; i++) {
            int apples_item = stoi(apples_temp[i]);

            if (apples_item >= -1e5 && apples_item <= 1e5) {
                apples[i] = apples_item;
            }
            else {
                apples_item = 0;
            }
        }

        string oranges_temp_temp;
        getline(cin, oranges_temp_temp);

        vector<string> oranges_temp = split(rtrim(oranges_temp_temp));

        vector<int> oranges(n);

        for (int i = 0; i < n; i++) {
            int oranges_item = stoi(oranges_temp[i]);
            if (oranges_item >= -1e5 && oranges_item <= 1e5) {
                oranges[i] = oranges_item;
            }
            else {
                oranges_item = 0;
            }
        }

        countApplesAndOranges(s, t, a, b, apples, oranges);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
