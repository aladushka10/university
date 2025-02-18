import { inject, Injectable } from "@angular/core"
import { Subject } from "../mock-subject-list"
import { Observable } from "rxjs"
import {
  collectionData,
  deleteDoc,
  doc,
  updateDoc,
  Firestore,
  collection,
  CollectionReference,
  addDoc,
} from "@angular/fire/firestore"

@Injectable({
  providedIn: "root",
})
export class SubjectsService {
  private dbPath = "data-subject-list"
  private subjectCollection: CollectionReference
  constructor(private db: Firestore) {
    db = inject(Firestore)
    this.subjectCollection = collection(this.db, this.dbPath)
  }

  getSubjects(): Observable<Subject[]> {
    return collectionData(this.subjectCollection, {
      idField: "id",
    }) as Observable<Subject[]>
  }

  removeSubject(deleteID: string) {
    const subjectDocRef = doc(this.db, `${this.dbPath}/${deleteID}`)
    deleteDoc(subjectDocRef)
  }

  update(editingSubject: Subject) {
    const subjectDocRef = doc(this.db, `${this.dbPath}/${editingSubject.id}`)
    updateDoc(subjectDocRef, {
      name: editingSubject.name,
      teacher: editingSubject.teacher,
    })
  }

  add(subject: Subject) {
    const cutedSubject = {
      name: subject.name,
      teacher: subject.teacher,
    }
    addDoc(this.subjectCollection, cutedSubject)
  }
}
