class Solution {
private:
    int convertToDays(string date) {
        int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        int totalDays = day;
        for (int i = 0; i < month - 1; ++i) {
            totalDays += daysInMonths[i];
        }
        return totalDays;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aliceArrival = convertToDays(arriveAlice);
        int aliceLeave = convertToDays(leaveAlice);
        int bobArrival = convertToDays(arriveBob);
        int bobLeave = convertToDays(leaveBob);

        int startTogether = max(aliceArrival, bobArrival);
        int endTogether = min(aliceLeave, bobLeave);

        return max(0, endTogether - startTogether + 1);
    }
};