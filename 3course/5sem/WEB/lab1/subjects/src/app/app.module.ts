import { NgModule } from "@angular/core"
import { BrowserModule } from "@angular/platform-browser"
import { AppRoutingModule } from "./app-routing.module"
import { AppComponent } from "./app.component"
import { SubjectsModule } from "./subjects/subjects.module"
import { FormsModule } from "@angular/forms";
import { initializeApp, provideFirebaseApp } from '@angular/fire/app';
import { getFirestore, provideFirestore } from '@angular/fire/firestore'

@NgModule({
  declarations: [AppComponent],
  imports: [FormsModule, BrowserModule, AppRoutingModule, SubjectsModule],
  providers: [
    provideFirebaseApp(() => initializeApp({"projectId":"subjects-70bf4","appId":"1:229934164381:web:adc1f61b305027b2596774","storageBucket":"subjects-70bf4.appspot.com","apiKey":"AIzaSyAYl8TGen5ffNbCtDxOHqPPgG0MeUnGMmg","authDomain":"subjects-70bf4.firebaseapp.com","messagingSenderId":"229934164381","measurementId":"G-ZBYZYFC0RD"})),
    provideFirestore(() => getFirestore())
  ],
  bootstrap: [AppComponent],
})
export class AppModule {}
