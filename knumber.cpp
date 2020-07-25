
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
	vector<int> answer;
	for (int i = 0;i<commands.size();i++)
	{
		vector<int> cut;
		for (int j = commands[i][0] - 1;j<commands[i][1];j++)
		{
			cut.push_back(array[j]);
		}
		sort(cut.begin(), cut.end());
		answer.push_back(cut.at(commands[i][2] - 1));
	}
	return answer;
}

int main() {
	vector<int> array = { 1,5,2,6,3,7,4 };
	vector<vector<int>> commands = { array ,{ 2,5,3 }, {4,4,1},{1,7,3} };

	for (int i = 1; i < 4; ++i)
	{
		cout << solution(array, commands)[i] << endl;
	}

}
