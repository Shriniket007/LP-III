#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

// Define a structure for tree nodes
struct Node
{
    char data;
    int frequency;
    Node *left;
    Node *right;

    Node(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
    Node(Node *left, Node *right) : data('\0'), frequency(left->frequency + right->frequency), left(left), right(right) {}
};

// Compare nodes by frequency
struct CompareNodes
{
    bool operator()(Node *left, Node *right)
    {
        return left->frequency > right->frequency;
    }
};

// Generate Huffman codes and store them in a map
map<char, string> generateHuffmanCodes(Node *root, string code = "")
{
    map<char, string> huffmanCodes;
    if (root == nullptr)
    {
        return huffmanCodes;
    }

    if (root->data != '\0')
    {
        huffmanCodes[root->data] = code;
    }

    map<char, string> leftCodes = generateHuffmanCodes(root->left, code + '0');
    huffmanCodes.insert(leftCodes.begin(), leftCodes.end());

    map<char, string> rightCodes = generateHuffmanCodes(root->right, code + '1');
    huffmanCodes.insert(rightCodes.begin(), rightCodes.end());

    return huffmanCodes;
}

int main()
{
    string input;
    cout << "Enter the input string: ";
    getline(cin, input);

    // Calculate character frequencies
    map<char, int> charFrequency;
    for (char c : input)
    {
        charFrequency[c]++;
    }

    // Create leaf nodes for each character
    priority_queue<Node *, vector<Node *>, CompareNodes> nodes;
    for (const auto &entry : charFrequency)
    {
        nodes.push(new Node(entry.first, entry.second));
    }

    // Build the Huffman tree
    while (nodes.size() > 1)
    {
        Node *left = nodes.top();
        nodes.pop();
        Node *right = nodes.top();
        nodes.pop();
        Node *newNode = new Node(left, right);
        nodes.push(newNode);
    }

    Node *huffmanRoot = nodes.top();

    // Generate Huffman codes
    map<char, string> huffmanCodes = generateHuffmanCodes(huffmanRoot);

    // Display the Huffman codes
    cout << " Char | Huffman code " << endl;
    cout << "----------------------" << endl;
    for (const auto &entry : charFrequency)
    {
        cout << " " << entry.first << "   |   " << huffmanCodes[entry.first] << endl;
    }

    // Clean up memory (free allocated nodes)
    while (!nodes.empty())
    {
        delete nodes.top();
        nodes.pop();
    }

    return 0;
}
