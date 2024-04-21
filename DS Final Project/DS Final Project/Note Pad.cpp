//#include <iostream>
//#include<fstream>
//#include<string>
//# include<map>
//using namespace std;
//#define MAX_TREE_HT 50
//string s = "";
//map<char, int> freq;
//map<char, string> codes;
//#define ALPHABET_SIZE (26)
//string arr[10000];
//int counter = 0;
//#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
//class HF
//{
//public:
//    char data;
//    int freq;
//    HF* l;
//    HF* r;
//    HF* ptr;
//    HF() {
//        data = ' ';
//        freq = 0;
//        l = r = ptr = NULL;
//    }
//};
//class MH
//{
//public:
//    int c;
//    int size;
//    HF** arr;
//};
//HF* top1 = NULL;
//class TrieNode {
//public:
//
//    class TrieNode* array2[ALPHABET_SIZE];
//
//    bool isWordEnd;
//};
//MH* createNode(int c)
//{
//    MH* t = new MH;
//    t->c = c;
//    t->size = 0;
//    t->arr = new HF * [c];
//    return t;
//}
//HF* node(char data, int freq)
//{
//    HF* newNode = new HF;
//    newNode->data = data;
//    newNode->freq = freq;
//    newNode->l = NULL;
//    newNode->r = NULL;
//    return newNode;
//}
//
//class TrieNode* getNode(void)
//{
//    class TrieNode* pNode = new TrieNode;
//    pNode->isWordEnd = false;
//
//    for (int i = 0; i < ALPHABET_SIZE; i++)
//        pNode->array2[i] = NULL;
//
//    return pNode;
//}
//void heapify(MH* heap, int n)
//{
//    int s = n;
//    int l = 2 * n + 1;
//    int r = 0;
//    r = 2 * r + 2;
//
//    if (l < heap->size && heap->arr[l]->freq < heap->arr[s]->freq)
//    {
//        s = l;
//    }
//    if (r < heap->size && heap->arr[r]->freq < heap->arr[s]->freq)
//    {
//        s = r;
//    }
//    if (s != n) {
//        swap(heap->arr[s], heap->arr[n]);
//        heapify(heap, s);
//    }
//}
//
//HF* DeleteH(MH* hp) {
//    HF* temp = hp->arr[0];
//    hp->arr[0] = hp->arr[hp->size - 1];
//    --hp->size;
//    heapify(hp, 0);
//    return temp;
//}
//int size1(MH* heap)
//{
//    return(heap->size == 1);
//}
//void MakeH(MH* heap)
//{
//    int nsize = heap->size - 1;
//    int i = (nsize - 1) / 2;
//    while (i > 0)
//    {
//        heapify(heap, i);
//        i--;
//    }
//}
//MH* heap(char item[], int freq[], int size)
//{
//    int i = 0;
//    MH* heap = createNode(size);
//    while (i < size)
//    {
//        heap->arr[i] = node(item[i], freq[i]);
//        i++;
//    }
//    heap->size = size;
//    MakeH(heap);
//    return heap;
//}
//void insert(MH* mh, HF* node)
//{
//    ++mh->size;
//    int child = mh->size - 1;
//
//    while (child && node->freq < mh->arr[(child - 1) / 2]->freq) {
//        mh->arr[child] = mh->arr[(child - 1) / 2];
//        child = (child - 1) / 2;
//    }
//    mh->arr[child] = node;
//}
//void storeCodes(HF* root, string str)
//{
//    if (root == NULL)
//        return;
//    if (root->data != '$')
//        codes[root->data] = str;
//    storeCodes(root->l, str + "0");
//    storeCodes(root->r, str + "1");
//}
//string decode_file(HF* root, string s)
//{
//    string ans = "";
//    HF* curr = root;
//    for (int i = 0; i < s.size(); i++) {
//        if (s[i] == '0')
//            curr = curr->l;
//        else
//            curr = curr->r;
//
//        if (curr->l == NULL and curr->r == NULL) {
//            ans += curr->data;
//            curr = root;
//        }
//    }
//
//    return ans + '\0';
//}
//void huffman_code(char item[], int freq[], int size)
//{
//    HF* lt = NULL, * rt = NULL;
//    MH* min = heap(item, freq, size);
//    while (size1(min) != 1)
//    {
//        lt = DeleteH(min);
//        rt = DeleteH(min);
//        top1 = node('$', lt->freq + rt->freq);
//        top1->l = lt;
//        top1->r = rt;
//        insert(min, top1);
//    }
//    storeCodes(top1, s);
//}
//int isLeaf(HF* root) {
//    return !(root->l) && !(root->r);
//}
//void insert(class TrieNode* root, const string key)
//{
//    class TrieNode* t = root;
//
//    for (int level = 0; level < key.length(); level++) {
//        int index = CHAR_TO_INDEX(key[level]);
//        if (!t->array2[index])
//            t->array2[index] = getNode();
//        t = t->array2[index];
//    }
//
//    t->isWordEnd = true;
//}
//
//bool isLastNode(class TrieNode* root)
//{
//    for (int i = 0; i < ALPHABET_SIZE; i++)
//        if (root->array2[i])
//            return 0;
//    return 1;
//}
//void suggestionsRec(class TrieNode* root,
//    string currPrefix)
//{
//
//    if (root->isWordEnd) {
//        arr[counter] = currPrefix;
//        counter++;
//    }
//    for (int i = 0; i < ALPHABET_SIZE; i++)
//        if (root->array2[i]) {
//
//            char child = 'a' + i;
//            suggestionsRec(root->array2[i],
//                currPrefix + child);
//        }
//}
//
//int print(TrieNode* root, const string query)
//{
//    class TrieNode* t = root;
//    for (char c : query) {
//        int ind = CHAR_TO_INDEX(c);
//
//        if (!t->array2[ind])
//            return 0;
//
//        t = t->array2[ind];
//    }
//
//    if (isLastNode(t)) {
//        cout << query << endl;
//        arr[0] = query;
//        return -1;
//
//    }
//    suggestionsRec(t, query);
//    return 1;
//}
//string space(string chr) {
//    int t = 0;
//    string ch = "";
//    for (int i = 0; i < chr.length(); i++) {
//        if (chr[i] == ' ') {
//            t++;
//        }
//    }
//    for (int i = 0; i < chr.length(); i++) {
//        if (t == 0) {
//            ch += chr[i];
//        }
//        if (chr[i] == ' ') {
//            t--;
//        }
//    }
//    return ch;
//}
//// Driver Code
//int main()
//{
//    int chk = 0;
//label1:
//
//    cout << "\n\n\n\n\t\t\t\t1-Continue last Document Editing\n\t\t\t\t2-New Document\n\t\t\t\t3-Group Member Details\n\t\t\t\t4-Project Details\n";
//    cout << "Enter Your Choice : ";
//    cin >> chk;
//    system("cls");
//    switch (chk) {
//    case 1:
//    {
//        char r;
//        string ch, str;
//        ifstream outfile1;
//        fstream outfile2;
//        fstream outfile3;
//        class TrieNode* root = getNode();
//        outfile1.open("outfile1.txt", ios::in);
//        while (!outfile1.eof()) {
//
//            outfile1 >> ch;
//            insert(root, ch);
//        }
//        outfile1.close();
//
//        int index = 0;
//        string read, choice;
//        string chr;
//        while (true)
//        {
//            int length = 0;
//            cin >> chr;
//            if (chr == "1")
//            {
//                goto EncodingGo;
//            }
//            outfile2.open("outfile2.txt", ios::app);
//            print(root, chr);
//            for (int i = 0; i < 10; i++)
//            {
//                cout << "\t_______________" << endl;
//                cout << '\t' << i + 1 << "->" << arr[i] << endl;
//            }
//            cout << "Index: ";
//            cin >> index;
//            if (index >= 0 && index < 10)
//                outfile2 << " " << arr[index - 1];
//            else
//            {
//                outfile2 << " " << chr;
//            }
//            system("cls");
//            outfile2.close();
//            outfile2.open("outfile2.txt", ios::in);
//            while (!outfile2.eof())
//            {
//                outfile2 >> read;
//                cout << read << " ";
//            }
//            outfile2.close();
//            for (int i = 0; i < 10; i++) {
//                arr[i] = "";
//            }
//            counter = 0;
//        }
//    EncodingGo:
//
//        string h;
//        outfile2.open("outfile2.txt", ios::in);
//        while (!outfile2.eof())
//        {
//            outfile2 >> h;
//            str += h;
//            str += " ";
//        }
//        outfile2.close();
//
//        int array[MAX_TREE_HT], top = 0;
//        int freq[26] = {}, f[26] = {};
//        char item[26] = {};
//        for (int i = 0; i < 26; i++)
//        {
//            freq[i] = 0;
//        }
//        for (int i = 0; i < str.size(); i++)
//            freq[str[i] - 'a']++;
//
//        for (int i = 0; i < str.size(); i++) {
//
//            if (freq[str[i] - 'a'] != 0) {
//                item[i] = str[i];
//                f[i] = freq[str[i] - 'a'];
//                freq[str[i] - 'a'] = 0;
//            }
//        }
//        huffman_code(item, freq, str.size());
//        for (auto v = codes.begin(); v != codes.end(); v++)
//            cout << v->first << ' ' << v->second << endl;
//        system("cls");
//        string encode, decode;
//        for (auto i : str)
//        {
//            encode += codes[i];
//        }
//        outfile3.open("outfile3.txt", ios::out);
//        outfile3 << encode;
//        outfile3.close();
//        outfile3.open("outfile3.txt", ios::in);
//        string word, s;
//        while (!outfile3.eof())
//        {
//            outfile3 >> word;
//            decode = decode_file(top1, word);
//            cout << decode << " ";
//        }
//        outfile3.close();
//        break;
//    }
//    case 2:
//    {
//        char r;
//        string ch, str;
//        ifstream outfile1;
//        fstream outfile2;
//        fstream outfile3;
//        class TrieNode* root = getNode();
//        outfile2.open("outfile2.txt", ios::out | ios::binary);
//        outfile2.close();
//        outfile1.open("outfile1.txt", ios::in);
//        while (!outfile1.eof()) {
//
//            outfile1 >> ch;
//            insert(root, ch);
//        }
//        outfile1.close();
//
//        int index = 0;
//        string read, choice;
//        string chr;
//        while (true)
//        {
//            int length = 0;
//            cin >> chr;
//            if (chr == "1")
//            {
//                goto EncodingGo1;
//            }
//            outfile2.open("outfile2.txt", ios::app);
//            print(root, chr);
//            for (int i = 0; i < 10; i++)
//            {
//                cout << "\t_______________" << endl;
//                cout << '\t' << i + 1 << "->" << arr[i] << endl;
//            }
//            cout << "Index: ";
//            cin >> index;
//            if (index >= 0 && index < 10)
//                outfile2 << " " << arr[index - 1];
//            else
//            {
//                outfile2 << " " << chr;
//            }
//            system("cls");
//            outfile2.close();
//            outfile2.open("outfile2.txt", ios::in);
//            while (!outfile2.eof())
//            {
//                outfile2 >> read;
//                cout << read << " ";
//            }
//            outfile2.close();
//            for (int i = 0; i < 10; i++) {
//                arr[i] = "";
//            }
//            counter = 0;
//        }
//    EncodingGo1:
//
//        string h;
//        outfile2.open("outfile2.txt", ios::in);
//        while (!outfile2.eof())
//        {
//            outfile2 >> h;
//            str += h;
//            str += " ";
//        }
//        outfile2.close();
//        int array[MAX_TREE_HT], top = 0;
//        int freq[26] = {}, f[26] = {};
//        char item[26] = {};
//        for (int i = 0; i < 26; i++)
//        {
//            freq[i] = 0;
//        }
//        for (int i = 0; i < str.size(); i++)
//            freq[str[i] - 'a']++;
//
//        for (int i = 0; i < str.size(); i++) {
//
//            if (freq[str[i] - 'a'] != 0) {
//                item[i] = str[i];
//                f[i] = freq[str[i] - 'a'];
//                freq[str[i] - 'a'] = 0;
//            }
//        }
//        huffman_code(item, freq, str.size());
//        for (auto v = codes.begin(); v != codes.end(); v++)
//            cout << v->first << ' ' << v->second << endl;
//        system("cls");
//        string encode, decode;
//        for (auto i : str)
//        {
//            encode += codes[i];
//        }
//        outfile3.open("outfile3.txt", ios::out);
//        outfile3 << encode;
//        outfile3.close();
//        outfile3.open("outfile3.txt", ios::in);
//        string word, s;
//        while (!outfile3.eof())
//        {
//            outfile3 >> word;
//            decode = decode_file(top1, word);
//            cout << decode << " ";
//        }
//        outfile3.close();
//        break;
//    }
//    case 3:
//    {
//        int choice3 = 0;
//        cout << "\n\n\n\tGroup Members : ";
//        cout << "\n\n\n\n\t\t1-Ali Haider\t\t21F-9192";
//        cout << "\n\n\n\n\t\t2-Muhammad Tayyab\t21F-9186";
//        cout << "\n\n\n\n\t\t3-Asad Ali\t\t21F-9203\n";
//        cout << "\n\nPress 1 For Continue : ";
//        cin >> choice3;
//        if (choice3 == 1) {
//            system("cls");
//            goto label1;
//        }
//        break;
//    }
//    case 4:
//    {
//        int choice3 = 0;
//        cout << "\n\n\n\t\t\t\t1-You Have To Write Data In Small Alphabets\n\n\n\n\t\t\t\t2-If You Want To Take Suggestions Just Press Enter On That Word\n";
//        cout << "\n\n\n\t\t\t\t3-If You Dont Want To take Suggestions Press Enter And Then Press -1\n";
//        cout << "\n\n\n\t\t\t\t4-When You Want Save Data On File In Encoding Form Press 1 While Typing\n";
//        cout << "\n\n\n\t\t\t\t5-If You Want To Stop Typing On Editor Press 1\n\n";
//        cout << "Press 1 For Continue : ";
//        cin >> choice3;
//        if (choice3 == 1) {
//            system("cls");
//            goto label1;
//        }
//        break;
//    }
//    }
//    return 0;
//}