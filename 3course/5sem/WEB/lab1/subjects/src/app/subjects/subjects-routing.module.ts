import { NgModule } from "@angular/core"
import { CommonModule } from "@angular/common"
import { RouterModule, Routes, Resolve } from "@angular/router"
import { SubjectCenterComponent } from "./subject-center/subject-center.component"
import { SubjectListComponent } from "./subject-list/subject-list.component"
import { SubjectDetailsComponent } from "./subject-details/subject-details.component"
import { SubjectFormComponent } from "./subject-form/subject-form.component"

const subjectCenterRouters: Routes = [
  {
    path: "",
    component: SubjectCenterComponent,
    children: [
      {
        path: "",
        component: SubjectListComponent,
      },
    ],
  },
  { path: "subject-form", component: SubjectFormComponent },
]

@NgModule({
  imports: [RouterModule.forChild(subjectCenterRouters)],
  exports: [RouterModule],
})
export class SubjectsRoutingModule {}
