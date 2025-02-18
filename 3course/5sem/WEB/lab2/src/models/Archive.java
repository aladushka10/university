package models;

import java.util.HashMap;
import java.util.Map;

public class Archive {
    private static Archive instance;
    private Map<Student, Map<Course, Integer>> grades = new HashMap<>();

    private Archive() {
    }

    public static Archive getInstance() {
        if (instance == null) {
            instance = new Archive();
        }
        return instance;
    }

    public void addGrade(Student student, Course course, int grade) {
        grades.computeIfAbsent(student, k -> new HashMap<>()).put(course, grade);
    }

    public Map<Course, Integer> getGrades(Student student) {
        return grades.get(student);
    }
}