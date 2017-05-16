#include <iostream>
#include <queue>

using namespace std;

class Node {
 public:
  int coeff;
  int pow;
};

class Comparator {
 public:
  bool operator()(Node& a, Node& b) { return a.pow < b.pow; }
};

int main() {
  int n;
  cin >> n;
  int coeff, pow;
  while (n--) {
    priority_queue<Node, vector<Node>, Comparator> add1, add2, result, f_result;
    do {
      Node node;
      cin >> node.coeff >> node.pow;
      if (node.pow < 0)
        break;
      else
        add1.push(node);
    } while (true);
    do {
      Node node;
      cin >> node.coeff >> node.pow;
      if (node.pow < 0)
        break;
      else
        add2.push(node);
    } while (true);

    while (!add1.empty() && !add2.empty()) {
      if (add1.top().pow == add2.top().pow) {
        Node node;
        node = add1.top();
        node.coeff += add2.top().coeff;
        result.push(node);
        add1.pop();
        add2.pop();
      } else if (add1.top().pow > add2.top().pow) {
        result.push(add1.top());
        add1.pop();
      } else if (add1.top().pow < add2.top().pow) {
        result.push(add2.top());
        add2.pop();
      }
    }

    while (!add1.empty()) {
      result.push(add1.top());
      add1.pop();
    }
    while (!add2.empty()) {
      result.push(add2.top());
      add2.pop();
    }

    Node node = result.top();
    result.pop();
    while (!result.empty()) {
      Node node1 = result.top();
      result.pop();
      if (node.pow == node1.pow) {
        node.coeff += node1.coeff;
      } else {
        f_result.push(node);
        node = node1;
      }
    }
    f_result.push(node);

    while (true) {
      int coeff = f_result.top().coeff;
      if (coeff != 0)
        cout << "[ " << coeff << " " << f_result.top().pow << " ]";
      f_result.pop();
      if (!f_result.empty()) {
        if (coeff != 0) cout << " ";
      } else {
        cout << endl;
        break;
      }
    }
  }
}
