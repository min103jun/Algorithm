#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef struct link* linklist;
typedef struct link {
	int n;
	linklist prev;
	linklist next;
	link(int num) {
		n = num;
		prev = NULL;
		next = NULL;
	}
}link;

linklist head = NULL;
stack<linklist> Stack;

string makelist(int n, string s)
{
	int i;
	linklist temp, prev, next = NULL;

	for (i = 0; i < n; i++)
		s += "O";
	for (i = 0; i < n; i++) {
		temp = new link(i);
		if (head == NULL) {
			head = temp;
			next = temp;
		}
		else {
			next->next = temp;
			temp->prev = next;
			next = temp;
		}

	}

	return s;
}

string solution(int n, int k, vector<string> cmd) {
	string answer = "";
	linklist idx, temp;
	int i, j, sz, pos;

	answer = makelist(n, answer);
	idx = head;
	for (i = 0; i < k; i++)
		idx = idx->next;

	sz = cmd.size();
	for (i = 0; i < sz; i++) {
		if (cmd[i][0] == 'U') {
			pos = stoi(cmd[i].substr(2));
			for (j = 0; j < pos; j++) {
				if (idx->prev != NULL)
					idx = idx->prev;
			}
		}
		else if (cmd[i][0] == 'D') {
			pos = stoi(cmd[i].substr(2));
			for (j = 0; j < pos; j++) {
				if (idx->next != NULL)
					idx = idx->next;
			}
		}
		else if (cmd[i][0] == 'C') {
			Stack.push(idx);
			if (idx->prev == NULL) {
				//헤드노드일경우
				idx->next->prev == NULL;
				idx = idx->next;
			}
			else if (idx->next == NULL) {
				//테일노드일 경우
				idx->prev->next = NULL;
				idx = idx->prev;
			}
			else {
				idx->prev->next = idx->next;
				idx->next->prev = idx->prev;
				idx = idx->next;
			}
		}
		else if (cmd[i][0] == 'Z') {
			temp = Stack.top();
			Stack.pop();
			if (temp->prev == NULL) {
				temp->next->prev = temp;
			}
			else if (temp->next == NULL) {
				temp->prev->next = temp;
			}
			else {
				temp->prev->next = temp;
				temp->next->prev = temp;
			}
		}
	}

	while (!Stack.empty()) {
		answer[Stack.top()->n] = 'X';
		Stack.pop();
	}
	return answer;
}
