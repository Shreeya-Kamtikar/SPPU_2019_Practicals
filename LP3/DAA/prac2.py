import heapq
from collections import Counter
class Node:     #define a node in the huffman tree
    def __init__(self, freq, symbol, left=None, right=None):
        self.freq = freq
        self.symbol = symbol
        self.left = left
        self.right = right
        self.huff = ''      #string to represent huffman code for the node
    def __lt__(self, nxt):      #compare based on frequencies for priority queue
        return self.freq < nxt.freq
    
def print_nodes(node, val=''):
    newVal = val + str(node.huff)
    if node.left:
        print_nodes(node.left, newVal)
    if node.right:
        print_nodes(node.right, newVal)
    if not node.left and not node.right:
        print(f"{node.symbol} -> {newVal}")

def create_huffman_tree(word):
    # chars = input("Enter characters (space separated): ").split()
    # freq = list(map(int, input("Enter frequencies (space separated): ").split()))
    # nodes = [Node(freq[i], chars[i]) for i in range(len(chars))]

    freq = Counter(word)
    nodes = [Node(freq[char],char) for char in freq]

    heapq.heapify(nodes)

    while len(nodes) > 1:
        left = heapq.heappop(nodes)
        right = heapq.heappop(nodes)
        left.huff = 0
        right.huff = 1
        newNode = Node(left.freq + right.freq, left.symbol + right.symbol, left, right)
        heapq.heappush(nodes, newNode)

    print_nodes(nodes[0])

word = input("Enter a word: ")
create_huffman_tree(word)