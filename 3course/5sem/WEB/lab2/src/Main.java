import models.Archive;
import models.Course;
import models.Student;
import models.Teacher;
import searchers.CourseSearcher;
import strategy.CourseSorter;
import strategy.SortByTitle;
import strategy.SortByTeacher;
import java.util.Arrays;
import java.util.List;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Teacher teacher1 = new Teacher("Smith");
        Teacher teacher2 = new Teacher("Johnson");

        Course course1 = new Course("Mathematics", teacher1);
        Course course2 = new Course("Physics", teacher2);
        Course course3 = new Course("History", teacher1);

        List<Course> courses = Arrays.asList(course1, course2, course3);

        Student student1 = new Student("Alice");
        Student student2 = new Student("Bob");

        student1.enroll(course1);
        student1.enroll(course3);

        student2.enroll(course2);
        student2.enroll(course3);

        System.out.println("\nCourses for " + student1 + ": " + student1.getCourses());
        System.out.println("Courses for " + student2 + ": " + student2.getCourses());

        CourseSorter sorter = new CourseSorter();
        sorter.setSortStrategy(new SortByTitle());

        System.out.println("\nBefore sorting by title:");
        courses.forEach(System.out::println);

        sorter.sortCourses(courses);

        System.out.println("\nAfter sorting by title:");
        courses.forEach(System.out::println);

        sorter.setSortStrategy(new SortByTeacher());
        sorter.sortCourses(courses);

        System.out.println("\nSorting by teacher name:");
        courses.forEach(System.out::println);

        Course foundCourse = CourseSearcher.searchCourseByTitle(courses, "Physics");
        if (foundCourse != null) {
            System.out.println("\nFound course: " + foundCourse);
        } else {
            System.out.println("\nCourse not found.");
        }

        Archive archive = Archive.getInstance();
        archive.addGrade(student1, course1, 85);  
        archive.addGrade(student1, course3, 90);  
        archive.addGrade(student2, course2, 78); 
        archive.addGrade(student2, course3, 88); 

        
        System.out.println("\nGrades for " + student1 + ": " + getGradesString(archive.getGrades(student1)));
        System.out.println("Grades for " + student2 + ": " + getGradesString(archive.getGrades(student2)));
    }

    private static String getGradesString(Map<Course, Integer> grades) {
        StringBuilder sb = new StringBuilder();
        for (Map.Entry<Course, Integer> entry : grades.entrySet()) {
            sb.append(entry.getKey().getTitle())
              .append(": ")
              .append(entry.getValue())
              .append("\n");
        }
        return sb.toString();
    }
}
