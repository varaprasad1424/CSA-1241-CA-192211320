#include <stdio.h>
#define TAKEN 1
#define NOT_TAKEN 0
#define STRONGLY_TAKEN 3
#define STRONGLY_NOT_TAKEN 0
typedef struct {
    int state;
} BranchPredictor;
void init_predictor(BranchPredictor *predictor) {
    predictor->state = STRONGLY_NOT_TAKEN;
}
int predict(BranchPredictor *predictor) {
    if (predictor->state >= 2) {
        return TAKEN;
    } else {
        return NOT_TAKEN;
    }
}
void update_predictor(BranchPredictor *predictor, int actual_outcome) {
    if (actual_outcome == TAKEN) {
        if (predictor->state < STRONGLY_TAKEN) {
            predictor->state++;
        }
    } else {
        if (predictor->state > STRONGLY_NOT_TAKEN) {
            predictor->state--;
        }
    }
}
int main() {
    BranchPredictor predictor;
    init_predictor(&predictor);
    int i;
    int branch_outcomes[] = {TAKEN, TAKEN, NOT_TAKEN, TAKEN, NOT_TAKEN};
    int num_branches = sizeof(branch_outcomes) / sizeof(branch_outcomes[0]);
    printf("Branch prediction results:\n");
    for (i = 0; i < num_branches; i++) {
        int prediction = predict(&predictor);
        printf("Branch %d: Prediction = %s\n", i + 1, prediction == TAKEN ? "Taken" : "Not Taken");
        update_predictor(&predictor, branch_outcomes[i]);
    }
	return 0;
}

