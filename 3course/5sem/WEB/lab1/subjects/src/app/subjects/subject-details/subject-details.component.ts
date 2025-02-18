import { Component, Input } from "@angular/core"
import { Subject } from "../mock-subject-list"

@Component({
  selector: "app-subject-details",
  templateUrl: "./subject-details.component.html",
  styleUrl: "./subject-details.component.css",
})
export class SubjectDetailsComponent {
  @Input() subject: Subject | undefined
}
