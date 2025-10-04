module MainWindow

open System.Windows
open System.Windows.Controls

let initializeWindow (window: Window) =
    let textBox = window.FindName("textBox") :?> TextBox
    let btnEnter = window.FindName("btnEnter") :?> Button
    let btnClear = window.FindName("btnClear") :?> Button

    btnEnter.Click.Add(fun _ ->
        textBox.Text <- "Hello world!"
    )

    btnClear.Click.Add(fun _ ->
        textBox.Text <- ""
    )

    window