import { NgModule } from "@angular/core"
import { CommonModule } from "@angular/common"
import { SubjectsRoutingModule } from "./subjects-routing.module"
import { SubjectCenterComponent } from "./subject-center/subject-center.component"
import { SubjectListComponent } from "./subject-list/subject-list.component"
import { SubjectDetailsComponent } from "./subject-details/subject-details.component"
import { SubjectFormComponent } from "./subject-form/subject-form.component"
import { FormsModule } from "@angular/forms"

@NgModule({
  declarations: [
    SubjectCenterComponent,
    SubjectListComponent,
    SubjectDetailsComponent,
    SubjectFormComponent,
  ],
  imports: [FormsModule, CommonModule, SubjectsRoutingModule],
})
export class SubjectsModule {}
