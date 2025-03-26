#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<vector>
#include<algorithm>
#include<set>

//файл из слов, определить частоту использования слов, создать новый файл с использованием слов с мин частотой
std::map<std::string, int> count_word_freq(const std::string& filename)
{
	std::map<std::string, int> res;
	std::ifstream file(filename);
	std::string word;
	while (file >> word)
		res[word]++;
	file.close();
	return res;
}
//ищет слова с мин частотой
std::vector<std::string> find_less_freq_word(const std::map<std::string, int>& word_freq)
{
	if (word_freq.empty())
		return {};
	//int min_freq = std::min_element(word_freq.begin(), word_freq.end(), [](const auto& a, const auto& b) {a.second < b.second; })->second;
	int min_freq = INT_MAX;
	for (const auto& pair : word_freq)
	{
		if (pair.second < min_freq)
			min_freq = pair.second;
	}
	std::vector<std::string> res;
	for (const auto& pair : word_freq)
	{
		if (pair.second == min_freq)
			res.push_back(pair.first);
	}
	return res;
}
void write_word_to_find(const std::vector<std::string>& words, const std::string& filename)
{
	std::ofstream file(filename);
	for (const auto& word : words)
		file << word << '\n';
	file.close();
}

//файл, содержится по одному слову, вывести в алф порядке все гласные, которые входят в одно слово
//функция проверяет гласная или нет
bool is_vowel(char ch)
{
	ch = tolower(ch);
	return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y');
}
//функция возвращает мн-во всех гласных в слове
std::set<char> get_vowels(const std::string& word)
{
	std::set<char> res;
	for (char ch : word)
	{
		if (is_vowel(ch))
			res.insert(ch);
	}
	return res;
}

//для каждого слова напечатать все пары: номер строки и индекс 1-го слова, для каждого попадания в файл: 
//слово координата 1-го вхождения отдельно, распечатать индекс, для котрого индекс начала строки макс
std::map<std::string, std::vector<std::pair<int, int>>> check_file(const std::string& filename)
{
	std::ifstream file(filename);
	std::string s;
	int str_num{ 0 };
	while (!file.eof())
	{
		std::getline(file, s);
		int i{ 0 };
		while (i < s.size())
		{
			while (s[i] == ' ' && i < s.size())
				i++;
			std::string word = "";
			int word_start = i;
			while (s[i] != ' ' && i < s.size())
			{
				word = word + s[i];
				i++;
			}
			res[word].push_back(pair);
		}
		str_num++;
	}
	while (file >> s)
	{

	}
	file.close();
}

int main()
{
	//task 1
	std::string input_file = "input.txt";
	/*std::string output_file = "output.txt";
	std::map<std::string, int> word_freq = count_word_freq(input_file);
	std::vector<std::string> words = find_less_freq_word(word_freq);
	write_word_to_find(words, output_file);
	for (const auto& pair : word_freq)
		std::cout << pair.first << ": " << pair.second << '\n';*/

	//task 2
	/*std::ifstream file(input_file);
	std::set<char> all_vowels;
	std::map<char, int> vowels_count;
	std::string word;
	while (file >> word)
	{
		std::set<char> word_vowels = get_vowels(word);
		for (char ch : word_vowels)
			vowels_count[ch]++;
		all_vowels.insert(word_vowels.begin(), word_vowels.end());
	}
	file.close();
	std::vector<char> res;
	/*for (char ch : all_vowels)
	{
		if (vowels_count[ch] == 1)
			res.push_back(ch);
	}
	for (char ch : res)
	{
		std::cout << ch << '\n';
	}*/

	//task 3 //дан файл, вывести все гласные в алф порядке, входящие в кадое слово
	/*std::ifstream file(input_file);
	std::set<char> all_vowels;
	all_vowels.insert('a');
	all_vowels.insert('e');
	all_vowels.insert('i');
	all_vowels.insert('o');
	all_vowels.insert('u');
	all_vowels.insert('y');
	std::string word;
	while (file >> word)
	{
		std::set<char> word_vowels = get_vowels(word);
		std::set<char> tmp;
		for (char ch : word_vowels)
		{
			if (all_vowels.find(ch) != all_vowels.end())
				tmp.insert(ch);

		}
		all_vowels = tmp;
	}
	file.close();
	for (char ch : all_vowels)
	{
		std::cout << ch << '\n';
	}*/

	std::ifstream file(input_file);
	std::set<char> all_vowels;
	std::string word;
	while (file >> word)
	{
		std::set<char> word_vowels = get_vowels(word);
		std::set<char> tmp;
		for (char ch : word_vowels)
		{
			if (all_vowels.find(ch) != all_vowels.end())
				tmp.insert(ch);

		}
		all_vowels = tmp;
	}
	file.close();
	for (char ch : all_vowels)
	{
		std::cout << ch << '\n';
	}

	std::cin.get();
	return 0;
}