package control

import (
	"TestFlow/model"
	"net/http"
)

func courses(w http.ResponseWriter, r *http.Request) {
	data := model.AllCoursec()
	tmpl := tmplFiles("view/course/courses.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

func createCourse(w http.ResponseWriter, r *http.Request) {
	data := model.CreateCourse()
	tmpl := tmplFiles("view/course/create-course.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

func getCourse(w http.ResponseWriter, r *http.Request) {
	id := getId(r.RequestURI)
	data := model.GetCourse(id)
	tmpl := tmplFiles("view/course/get-course.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

func updateCourse(w http.ResponseWriter, r *http.Request) {
	data := model.UpdateCourse()
	tmpl := tmplFiles("view/course/update-course.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

func deleteCourse(w http.ResponseWriter, r *http.Request) {
	model.DeleteCourse()

	http.Redirect(w, r, "/courses/", http.StatusSeeOther)
}
