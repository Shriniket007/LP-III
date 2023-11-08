#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class HuffmanNode
{
public:
    char data;
    int frequency;
    HuffmanNode *left;
    HuffmanNode *right;

    HuffmanNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}

    bool operator>(const HuffmanNode &other) const
    {
        return frequency > other.frequency;
    }
};

void printHuffmanCodes(HuffmanNode *node, string code)
{
    if (node == nullptr)
        return;

    if (node->data != '\0')
    {
        cout << node->data << ": " << code << endl;
    }

    printHuffmanCodes(node->left, code + "0");
    printHuffmanCodes(node->right, code + "1");
}

int main()
{
    string text = "encoding";

    unordered_map<char, int> frequencies;
    for (char c : text)
    {
        frequencies[c] += 1;
    }

    priority_queue<HuffmanNode, vector<HuffmanNode>, greater<HuffmanNode>> minHeap;
    for (const auto &entry : frequencies)
    {
        minHeap.push(HuffmanNode(entry.first, entry.second));
    }

    while (minHeap.size() > 1)
    {
        HuffmanNode *left = new HuffmanNode(minHeap.top());
        minHeap.pop();
        HuffmanNode *right = new HuffmanNode(minHeap.top());
        minHeap.pop();
        HuffmanNode *parent = new HuffmanNode('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        minHeap.push(*parent);
    }

    HuffmanNode root = minHeap.top();
    printHuffmanCodes(&root, "");
    return 0;
}