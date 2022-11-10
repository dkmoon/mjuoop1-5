#include <list>
#include <iostream>

using namespace std;


const int MAX_MEMBERS = 1000;
const int NUM_SELECTED = 5;
const int NUM_ACTIVITIES = 2000;


class Navy {
private:
	int id;
	time_t lastAtiveTime;

public:
	Navy(int id);

	int getId() const;
	void updateActiveTime();
};

Navy::Navy(int id) : id{ id } {

}

inline int Navy::getId() const {
	return id;
}

void Navy::updateActiveTime() {
	lastAtiveTime = time(NULL);
}


int main() {

	// 랜덤 시드 초기화
	srand(time(NULL));

	list<Navy*> members;

	// 멤버 리스트 초기화
	for (int i = 0; i < MAX_MEMBERS; ++i) {
		members.push_back(new Navy(i));
	}

	// 랜덤하게 활동 기록 만들기
	for (int i = 0; i < NUM_ACTIVITIES; ++i) {
		// 활동을 만들 멤버 찾기
		int id = rand() % MAX_MEMBERS;

		list<Navy*>::iterator it;
		for (it = members.begin(); it != members.end(); ++it) {
			Navy* member = *it;
			if (member->getId() == id) {
				break;
			}
		}

		if (it != members.end()) {
			Navy* member = *it;
			members.erase(it);
			members.push_front(member);
		}
	}

	// 선별된 멤버 출력
	list<Navy*>::const_iterator it = members.cbegin();
	for (int i = 0; i < NUM_SELECTED && it != members.cend(); ++i) {
		Navy* member = *it;
		cout << member->getId() << endl;
		++it;
	}
}
