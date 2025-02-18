package strategy;

import models.Course;
import java.util.List;

public interface SortStrategy {
    void sort(List<Course> courses);
}
