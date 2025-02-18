package strategy;

import models.Course;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class SortByTitle implements SortStrategy {
    @Override
    public void sort(List<Course> courses) {
        Collections.sort(courses, Comparator.comparing(Course::getTitle));
    }
}
