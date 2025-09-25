#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.first == b.first) {
            // ���ϰ� ���Ƚ�� ���� ��
            return a.second > b.second;  // ������ȣ ��������
        }
        return a.first < b.first;  // ��ҿ� �뷡 ��������
    }
};


vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> numGenre;
    vector<pair<int, int>> seqGenre(100);  // i�� �帣�� ��� ����Ƴ�
    int num = 0;   // �帣 ����
    for (int i = 0; i < genres.size(); i++)
    {
        if (numGenre.find(genres[i]) != numGenre.end())
        {
            // �ִ� ���
            seqGenre[numGenre[genres[i]]].first += plays[i];
            seqGenre[numGenre[genres[i]]].second++;
        }
        else {
            numGenre[genres[i]] = num;
            seqGenre[num].first += plays[i];
            seqGenre[num].second = 1;
            num++;
        }
    }

    // �帣 ��������
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < num; i++)
    {
        pq.push({ seqGenre[i].first, i });  // �帣 ���ϰ� ��� ����ƴ���, num�帣 ��ȣ
    }

    vector<pair<int, int>> idx(num);
    int pidx = 0;

    while (!pq.empty())
    {
        int seq = pq.top().first, numG = pq.top().second;
        pq.pop();
        idx[numG].first = pidx;
        idx[numG].second = 0;  // ��¥ �Ǹ� ���ϰ��� 2������
        // �帣�� ���ϰ� 2�� �ʰ�����
        if (seqGenre[numG].second >= 2) pidx += 2;
        else pidx += 1;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> seqPq;
    for (int i = 0; i < plays.size(); i++)
    {
        seqPq.push({ plays[i], i });   // ���ϰ� ��� Ƚ��, ������ȣ
    }

    vector<int> answer(pidx, 0);
    while (!seqPq.empty())
    {
        int goyou = seqPq.top().second;
        int numG = numGenre[genres[goyou]];
        seqPq.pop();
        if (idx[numG].second < 2)
        {
            answer[idx[numG].first] = goyou;
            idx[numG].first++;
            idx[numG].second++;
        }
    }

    return answer;
}
