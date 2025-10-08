module MainWindow

open System
open System.Windows
open System.Windows.Controls

open functions


let initializeWindow (window: Window) =
    
    // Элементы управления
    let btnInsert = window.FindName("btnInsert") :?> Button    
    let btnScan = window.FindName("btnScan") :?> Button
    let btnClear = window.FindName("btnClear") :?> Button
    let btnLarge = window.FindName("btnLarge") :?> Button
    let btnSmall = window.FindName("btnSmall") :?> Button
    let textBox = window.FindName("textBox") :?> TextBox
    let value1 = window.FindName("value1") :?> TextBlock
    let value2 = window.FindName("value2") :?> TextBlock
    let value3 = window.FindName("value3") :?> TextBlock
    let itemsListBox = window.FindName("itemsListBox") :?> ListBox
    let items = [|
        "Человеческий научный текст";
        "Человеческий законодательный текст";
        "Человеческий литературный текст";
        "Человеческий журналистский текст";
        "Человеческий текст из соц.сетей";
        "Нейросеть Grok (xAI)";
        "Нейросеть ChatGPT (Google)";
        "Нейросеть DeepSeek AI";
        "Нейросеть GPT-4 (OpenAI)";
        "Нейросеть Claude 3 (Anthropic)";
        "Нейросеть YandexGPT";
        "Нейросеть Bloom (BigScience)";
        "Нейросеть LaMDA (Google)";
        "Аномальный стиль текста";
        "Неопределенный текст"|]
    itemsListBox.ItemsSource <- items

    // Изменение размера шрифта с ограничениями
    let minFontSize = 8.0
    let maxFontSize = 24.0
    let mutable fontSize = 12.0
    let updateFontSize delta =
        let newSize = fontSize + delta
        if newSize >= minFontSize && newSize <= maxFontSize then
            fontSize <- newSize
            textBox.FontSize <- fontSize
            btnLarge.IsEnabled <- fontSize < maxFontSize
            btnSmall.IsEnabled <- fontSize > minFontSize

    // Вставка текста из буфера обмена
    btnInsert.Click.Add(fun _ ->
        try
            if Clipboard.ContainsText() then
                let clipboardText = Clipboard.GetText()
                textBox.Text <- clipboardText
            else
                textBox.Text <- "Буфер обмена не содержит текста"
        with
        | ex -> 
            textBox.Text <- sprintf "Ошибка при вставке из буфера обмена: %s" ex.Message
    )

    // Отправка текста на анализ  **** ДОПЕРЕДЕЛАТЬ ****
    btnScan.Click.Add(fun _ ->
        value1.Text <- scan textBox.Text |> sprintf "%d"
        value2.Text <- scan2 textBox.Text |> sprintf "%d"
        value3.Text <- scan3 textBox.Text |> sprintf "%d"
    )

    // Очистка текстового окна
    btnClear.Click.Add(fun _ ->
        textBox.Clear()
    )

    // Увеличить шрифт
    btnLarge.Click.Add(fun _ ->
        updateFontSize 1.0
    )
    
    // Уменьшить шрифт
    btnSmall.Click.Add(fun _ ->
        updateFontSize -1.0
    )

    // *********************************************************
    //         ВСЕ ДОПЕРЕДЕЛАТЬ И ПЕРЕДООПТИМИЗИРОВАТЬ
    // *********************************************************

    // Обработчик события выбора элемента
    itemsListBox.SelectionChanged.AddHandler(fun sender e ->
        match itemsListBox.SelectedItem with
        | :? string as selectedItem ->
            // Используем выбранный элемент
            printfn "Выбран: %s" selectedItem
            // Здесь можно добавить вашу логику обработки выбора
        | _ -> ()
    )

    // Метод для получения выбранного элемента
    let getSelectedItem() =
        match itemsListBox.SelectedItem with
        | :? string as item -> Some item
        | _ -> None

    // Метод для установки выбранного элемента по индексу
    let setSelectedItem index =
        if index >= 0 && index < itemsListBox.Items.Count then
            itemsListBox.SelectedIndex <- index

    // Метод для установки выбранного элемента по значению
    let setSelectedItemByValue (value: string) =
        let index = Array.tryFindIndex (fun item -> item = value) items
        match index with
        | Some i -> itemsListBox.SelectedIndex <- i
        | None -> ()

    // *********************************************************

    window