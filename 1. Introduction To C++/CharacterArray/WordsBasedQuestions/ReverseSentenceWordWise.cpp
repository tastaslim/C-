#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int len(char input[])
{
	int k = 0;
	for (int i = 0; input[i] != '\0'; i++)
		k++;
	return k;
}

void ReverseSentence(char input[])
{
	int i = 0, j = len(input) - 1;
	while (i < j)
	{
		swap(input[i++], input[j--]);
	}
}
void ReverseWord(char input[], int start, int end)
{
	int i = start, j = end;
	while (i < j)
	{
		char c = input[i];
		input[i] = input[j];
		input[j] = c;
		i = i + 1;
		j = j - 1;
		// swap(input[i++], input[j--]);
	}
}

void Reverse(char input[])
{
	ReverseSentence(input);
	int start = 0, end = 0, i = 0;
	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == ' ')
		{
			end = i - 1;
			ReverseWord(input, start, end);
			start = i + 1;
		}
	}
	end = i - 1;
	ReverseWord(input, start, end);
}

int main()
{
	char input[1000000];
	cin.getline(input, 1000000);
	Reverse(input);
	cout << input << endl;
}