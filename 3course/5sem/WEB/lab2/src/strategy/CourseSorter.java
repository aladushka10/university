package strategy;

import models.Course;
import java.util.List;

public class CourseSorter {
    private SortStrategy strategy;

    public void setSortStrategy(SortStrategy strategy) {
        this.strategy = strategy;
    }

    public void sortCourses(List<Course> courses) {
        if (strategy != null) {
            strategy.sort(courses);
        }
    }
}
