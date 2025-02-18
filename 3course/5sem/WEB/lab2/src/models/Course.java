package models;

public class Course {
    private String title;
    private Teacher teacher;

    public Course(String title, Teacher teacher) {
        this.title = title;
        this.teacher = teacher;
    }

    public String getTitle() {
        return title;
    }

    public Teacher getTeacher() {
        return teacher;
    }

    @Override
    public String toString() {
        return title + " (Teacher: " + teacher + ")";
    }
}
