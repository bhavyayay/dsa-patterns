class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        int firstCriticalIndex = -1;
        int previousCriticalIndex = -1;

        int prev = 0;
        int curr = 0;
        int next = 0;

        vector<int> result = {-1, -1};

        int mindist = INT_MAX;
        int i = 0;

        while (head != NULL) {

            prev = curr;
            curr = next;
            next = head->val;

            if (i >= 2 &&
                ((prev > curr && curr < next) ||
                 (prev < curr && curr > next))) {

                if (firstCriticalIndex == -1) {
                    firstCriticalIndex = i - 1;
                }
                else {
                    mindist = min(mindist,
                                  (i - 1) - previousCriticalIndex);

                    result = {
                        mindist,
                        (i - 1) - firstCriticalIndex
                    };
                }

                previousCriticalIndex = i - 1;
            }

            i++;
            head = head->next;
        }

        return result;
    }
};