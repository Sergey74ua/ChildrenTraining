module MainWindow

open System
open System.Windows
open System.Windows.Controls

open functions


let initializeWindow (window: Window) =
    let textBox = window.FindName("textBox") :?> TextBox
    let btnEnter = window.FindName("btnEnter") :?> Button
    let btnClear = window.FindName("btnClear") :?> Button

    btnEnter.Click.Add(fun _ ->
        textBox.Text <- "Hello world!"
    )

    btnClear.Click.Add(fun _ ->
        let t = textBox.Text
        textBox.Clear()
        let n = count t |> sprintf "Символов: %d"
        textBox.Text <- t + Environment.NewLine + n
    )

    window