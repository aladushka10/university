package searchers;
import models.Course;

import java.util.List;

public class CourseSearcher {
    public static Course searchCourseByTitle(List<Course> courses, String title) {
        for (Course course : courses) {
            if (course.getTitle().equalsIgnoreCase(title)) {
                return course;
            }
        }
        return null;
    }
}
