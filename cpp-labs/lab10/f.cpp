#include <bits/stdc++.h> 
using namespace std;


double wow(int att1, int att2, int final, int credits) {
    int totalMarks = att1 + att2 + final;

    if (att1 + att2 < 30 || final < 20) {
        return 0;
    }

    double gradePoint = 0.0;
    if (totalMarks >= 95) {
        gradePoint = 4.0;
    } else if (totalMarks >= 50) {
        gradePoint = 1.0 + ((totalMarks - 50) / 5) * (1.0 / 3.0);
    }

    return gradePoint * credits;
}

int main() {
    int n;
    cin >> n;

    double totalGradePoints = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < n; ++i) {
        int att1, att2, final, credits;
        cin >> att1 >> att2 >> final >> credits;

        double gradePoints = wow(att1, att2, final, credits);

        totalGradePoints += gradePoints;
        totalCredits += credits;
    }

    double GPA = totalGradePoints / totalCredits;

    cout << fixed << setprecision(6) << GPA << endl;

    return 0;
}

