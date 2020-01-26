
//Program : to find the count of a word in a given sentence/paragraph.

#include<iostream>
#include<string>
#include<map>
using namespace std;

void add_to_map(const string& word, map<string, int> &wc)
{
	if ( (wc.find(word) == wc.end()) )   //if word is not present
		wc.insert({ word,1 });
	else    //word is present so increment its count
		wc[word]++;

}

//split string based on Characters other than Alpha/numerics.
void count_word(string input,map<string,int> &word_count) 
{
	
	//Algo : 
	// 1. Split the input into words.
	// 2. add this word into maps. fun- add_to_map()

	string word;
	for (int i = 0 ;; i++)
	{
		if (isalnum(input[i]))
			word += input[i];
		else if (word.length()!=0 && (!isalnum(input[i])))
		{
			add_to_map(word, word_count);
			word.clear();
		}

		if (input[i + 1] == '\0' )
		{
			if(!word.empty())                       //checking for str = "hello,"
				add_to_map(word, word_count);
			word.clear();
			break;
		}
	}
}
int main()
{
	string input;
	map<string, int> word_count;

	cout << "Enter Sentence/Paragraph: ";
	do {
		getline(cin, input);
		if (input.empty())
			cout << "Input cannot be empty, enter again!!" << endl;
	} while (input.empty());
	
	count_word(input,word_count);
	
	string word;

	cout << endl << "Finding Count of Word - Enter Word: ";
	do {
		getline(cin, word);
		if (word.empty())
			cout << "Input cannot be empty, enter again!!" << endl;
	} while (word.empty());
	
	cout << endl << "Count of word \"" << word << "\" is: " << word_count[word] << endl ;

	cin.ignore();
	cin.get();
	
	//Print map 

	//for (map<string, int>::iterator itr = word_count.begin(); itr != word_count.end(); itr++)
		//cout << itr->first << "\t" << itr->second << endl;
	
	return 0;
}

//Code snippet for spliting string based on (start_index) and (length of a word) params.

/*for (int i = 0,j=0, len=0; input[i]; i++)
	{
		if (!isalnum(input[i]) && i!=input.length() - 1)
		{
			add_to_map(input.substr(j, len), word_count);
			while (!isalnum(input[++i]));
			j = i;
			len = 0;
		}
		else if ( i == input.length() - 1)
			add_to_map(input.substr(j, input.length()), word_count);
		len++;
			
	}*/