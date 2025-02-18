import { Component, OnInit } from '@angular/core';
import { Subject } from '../mock-subject-list';
import { SubjectsService } from '../service/subjects.service';
import { FormBuilder } from '@angular/forms';
@Component({
  selector: 'app-subject-form',
  templateUrl: './subject-form.component.html',
  styleUrl: './subject-form.component.css',
})
export class SubjectFormComponent implements OnInit {
  subjects: Subject[] = [];
  subject: Subject = { id: '', name: '', teacher: '' };
  editing: boolean = false;

  constructor(private subjectsService: SubjectsService) {}

  updateSubjects(): void {
    this.subjectsService.getSubjects().subscribe((subjects) => {
      this.subjects = subjects;
    });
  }

  ngOnInit(): void {
    this.updateSubjects();
  }

  onSubmit(form: any) {
    if (form.valid) {
      if (!this.editing) {
        this.subjectsService.add(this.subject);
      } else {
        this.subjectsService.update(this.subject);
      }
      this.updateSubjects();
      this.cancelEditing();
    }
  }

  onEditing(editingSubject: Subject) {
    this.subject = editingSubject;
    this.editing = true;
  }

  onDelete(deleteSubject: Subject) {
    this.subjectsService.removeSubject(deleteSubject.id);
    this.cancelEditing();
  }

  cancelEditing() {
    this.editing = false;
    this.subject = { id: '', name: '', teacher: '' };
  }
}
