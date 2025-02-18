package models;

import java.util.ArrayList;
import java.util.List;

public class Student {
    private String name;
    private List<Course> courses = new ArrayList<>();

    public Student(String name) {
        this.name = name;
    }

    public void enroll(Course course) {
        courses.add(course);
    }

    public List<Course> getCourses() {
        return courses;
    }

    @Override
    public String toString() {
        return name;
    }
}
