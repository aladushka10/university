import { Component, OnInit } from '@angular/core';
import { SubjectsService } from '../service/subjects.service';
import { Subject } from '../mock-subject-list';

@Component({
  selector: 'app-subject-list',
  templateUrl: './subject-list.component.html',
  styleUrl: './subject-list.component.css',
})
export class SubjectListComponent implements OnInit {
  subjects: Subject[] = [];
  selectedSubjectId: string | null = null;
  constructor(private subjectsService: SubjectsService) {}

  ngOnInit(): void {
    this.subjectsService.getSubjects().subscribe((subjects) => {
      this.subjects = subjects;
    });
  }

  toggleDetails(id: string): void {
    this.selectedSubjectId = this.selectedSubjectId === id ? null : id;
  }
}
