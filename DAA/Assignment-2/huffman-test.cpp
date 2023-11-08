#include <bits/stdc++.h>
using namespace std;

// Define the Node structure for the Huffman tree
struct Node
{
    char data;
    int frequency;
    Node *left;
    Node *right;

    Node(char d, int f)
    {
        this->data = d;
        this->frequency = f;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Define a comparison function for nodes in the priority queue
struct CompareNodes
{
    bool operator()(Node *a, Node *b) { return a->frequency > b->frequency; }
};

map<char, string> huffmanCodes; // Map to store Huffman codes

// Function to generate Huffman codes and populate the huffmanCodes map
void generateHuffmanCodes(Node *root, string code = "")
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        huffmanCodes[root->data] = code;
        cout << root->data << ": " << code << endl; // Display Huffman codes in the console
    }
    generateHuffmanCodes(root->left, code + "0");
    generateHuffmanCodes(root->right, code + "1");
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    // Calculate character frequencies
    map<char, int> freq;
    for (char c : s)
        freq[c]++;

    // Create a priority queue for nodes
    priority_queue<Node *, vector<Node *>, CompareNodes> pq;
    for (auto p : freq)
        pq.push(new Node(p.first, p.second));

    // Build the Huffman tree
    while (pq.size() > 1)
    {
        Node *l = pq.top();
        pq.pop();
        Node *r = pq.top();
        pq.pop();
        Node *n = new Node('\0', l->frequency + r->frequency);
        n->left = l;
        n->right = r;
        pq.push(n);
    }

    // Generate Huffman codes and populate the huffmanCodes map
    generateHuffmanCodes(pq.top());

    // Concatenate Huffman codes for the input string
    string concatenatedCodes;
    for (char c : s)
    {
        concatenatedCodes += huffmanCodes[c];
    }

    cout << "Concatenated Huffman Codes: " << concatenatedCodes << endl;

    return 0;
}