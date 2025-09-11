#include <iostream>
#include <cmath>

int main();

int inputMaxMark(std::string assignment) {
    double max_mark{};
    std::cout << "Please enter the maximum grade for the " << assignment << ": " << std::endl;
    std::cin >> max_mark;
    // std::cout << max_mark << std::endl; 
    while(max_mark <= 0 || max_mark != std::round(max_mark)) {
        std::cout << "This is not a valid grade, please try again: " << std::endl;
        std::cin >> max_mark;
    }
    return max_mark;
}

double inputAchievedMark(std::string assignment, int max_mark) {
    double achieved_mark{};
    std::cout << "Please enter your achieved grade for the " << assignment << ": " << std::endl;
    std::cin >> achieved_mark;
    while(achieved_mark < 0 || achieved_mark > max_mark) {
        std::cout << "This is not a valid grade, please try again: " << std::endl;
        std::cin >> achieved_mark;
    }
    achieved_mark = 100*(achieved_mark/max_mark);
    return achieved_mark;
}

double compare_final(double grade, double final_exam_grade) {
    if (grade < final_exam_grade) {
        return final_exam_grade;
    }
    return grade;
}

int main() {
    int final_exam_max_grade{inputMaxMark("final examination")};
    double final_exam_achieved_grade{inputAchievedMark("final examination", final_exam_max_grade)};

    // std::cout << final_exam_achieved_grade << std::endl;
    // std::cout << final_exam_max_grade << std::endl;
    
    int midterm_exam_max_grade{inputMaxMark("midterm examination")};
    double midterm_exam_achieved_grade{compare_final(inputAchievedMark("midterm examination", midterm_exam_max_grade), final_exam_achieved_grade)};
    
    // std::cout << midterm_exam_achieved_grade << std::endl;
    // std::cout << midterm_exam_max_grade << std::endl;

    int project1_max_grade{inputMaxMark("Project 1")};
    double project1_achieved_grade{compare_final(inputAchievedMark("Project 1", project1_max_grade), final_exam_achieved_grade)};

    int project2_max_grade{inputMaxMark("Project 2")};
    double project2_achieved_grade{compare_final(inputAchievedMark("Project 2", project2_max_grade), final_exam_achieved_grade)};

    int project3_max_grade{inputMaxMark("Project 3")};
    double project3_achieved_grade{compare_final(inputAchievedMark("Project 3", project3_max_grade), final_exam_achieved_grade)};

    int project4_max_grade{inputMaxMark("Project 4")};
    double project4_achieved_grade{compare_final(inputAchievedMark("Project 4", project4_max_grade), final_exam_achieved_grade)};

    int project5_max_grade{inputMaxMark("Project 5")};
    double project5_achieved_grade{compare_final(inputAchievedMark("Project 5", project5_max_grade), final_exam_achieved_grade)};

    double achieved_weighted_exam_average{0.75*final_exam_achieved_grade+0.25*midterm_exam_achieved_grade};

    // std::cout << "P" << project1_achieved_grade << std::endl;
    // std::cout << "P" << project2_achieved_grade << std::endl;
    // std::cout << "P" << project3_achieved_grade << std::endl;
    // std::cout << "P" << project4_achieved_grade << std::endl;
    // std::cout << "P" << project5_achieved_grade << std::endl;

    double average_achieved_project_grade{(project1_achieved_grade+project2_achieved_grade+project3_achieved_grade+project4_achieved_grade+project5_achieved_grade)/5};

    // std::cout << "PA" << average_achieved_project_grade << std::endl;

    double final_average{0};

    // std::cout << "E" << achieved_weighted_exam_average << std::endl;

    if(achieved_weighted_exam_average <= 40) {
        final_average = achieved_weighted_exam_average;
    }
    else if (achieved_weighted_exam_average >= 60) {
        final_average = 2.0/3.0*achieved_weighted_exam_average + average_achieved_project_grade/3;
    }
    else {
        final_average = average_achieved_project_grade*(achieved_weighted_exam_average-40.0)/60.0 + achieved_weighted_exam_average*(1.0 - (achieved_weighted_exam_average-40.0)/60.0);
    }

    // std::cout << "RF" << final_average << std::endl;
    final_average = std::round( final_average + 1e-12 );
    std::cout << final_average << std::endl;

    return 0;
}

// 60 33.0 60 33.0 90 85 30 15 25 4 80 26 10 6
