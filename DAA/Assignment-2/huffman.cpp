#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>

using namespace std;

struct HuffmanNode
{
    char data;
    int freq;
    HuffmanNode *left, *right;

    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

struct CompareHuffmanNode
{
    bool operator()(HuffmanNode *a, HuffmanNode *b)
    {
        return a->freq > b->freq;
    }
};

HuffmanNode *buildHuffmanTree(map<char, int> &freqMap)
{
    priority_queue<HuffmanNode *, vector<HuffmanNode *>, CompareHuffmanNode> minHeap;

    for (const auto &entry : freqMap)
    {
        minHeap.push(new HuffmanNode(entry.first, entry.second));
    }

    while (minHeap.size() > 1)
    {
        HuffmanNode *left = minHeap.top();
        minHeap.pop();
        HuffmanNode *right = minHeap.top();
        minHeap.pop();
        HuffmanNode *internalNode = new HuffmanNode('\0', left->freq + right->freq);
        internalNode->left = left;
        internalNode->right = right;
        minHeap.push(internalNode);
    }

    return minHeap.top();
}

void generateHuffmanCodes(HuffmanNode *root, string code, map<char, string> &huffmanCodes)
{
    if (!root)
        return;
    if (root->data != '\0')
        huffmanCodes[root->data] = code;
    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

string huffmanEncode(string text, map<char, string> &huffmanCodes)
{
    string encodedText = "";
    for (char c : text)
    {
        encodedText += huffmanCodes[c];
    }
    return encodedText;
}

int main()
{
    string text;
    cout << "Enter a string to encode using Huffman: ";
    cin >> text;

    map<char, int> freqMap;
    for (char c : text)
        freqMap[c]++;

    HuffmanNode *root = buildHuffmanTree(freqMap);
    map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    string encodedText = huffmanEncode(text, huffmanCodes);

    // Print the Huffman codes table
    cout << "Huffman Codes Table:" << endl;
    for (const auto &entry : huffmanCodes)
    {
        cout << entry.first << " : " << entry.second << endl;
    }

    cout << "Encoded text: " << encodedText << endl;

    return 0;
}