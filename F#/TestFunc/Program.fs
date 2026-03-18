open System
open System.Text.RegularExpressions

// Функция для очистки текста от лишних символов
let cleanText (text: string) = 
    text.Trim()

// Функция для разделения текста на слова
let splitWords (text: string) =
    let words = Regex.Matches(text, @"\b[\w']+\b")
    words |> Seq.cast<Match> |> Seq.map (fun m -> m.Value)

// Функция для разделения текста на предложения
let splitSentences (text: string) =
    let sentences = Regex.Split(text, @"[.!?]+")
    sentences 
    |> Array.map cleanText 
    |> Array.filter (fun s -> not (String.IsNullOrWhiteSpace s))

// 1. Подсчет вхождений символов (возвращает Map<char, int>)
let countCharacters (text: string) =
    text
    |> Seq.filter (fun c -> not (Char.IsWhiteSpace c)) // Игнорируем пробелы
    |> Seq.countBy id
    |> Map.ofSeq

// 2. Подсчет слов по длинам (возвращает Map<int, int>)
let countWordsByLength (text: string) =
    splitWords text
    |> Seq.map (fun word -> word.Length)
    |> Seq.countBy id
    |> Map.ofSeq

// 3. Подсчет предложений по количеству слов (возвращает Map<int, int>)
let countSentencesByWordCount (text: string) =
    splitSentences text
    |> Seq.map (fun sentence -> 
        splitWords sentence |> Seq.length)
    |> Seq.countBy id
    |> Map.ofSeq

// Основная функция анализа - возвращает кортеж из трех словарей
let analyzeText (text: string) =
    let cleanedText = cleanText text
    
    (
        countCharacters cleanedText,      // Map<char, int>
        countWordsByLength cleanedText,   // Map<int, int>
        countSentencesByWordCount cleanedText  // Map<int, int>
    )

// Вспомогательные функции для красивого вывода результатов
let printAnalysis (text: string) =
    let charStats, wordStats, sentenceStats = analyzeText text
    
    printfn "Анализ текста:"
    printfn "%s" (String.replicate 50 "=")
    
    printfn "\n1. Частота символов:"
    charStats
    |> Map.toSeq 
    |> Seq.sortBy fst 
    |> Seq.iter (fun (char, count) -> 
        printfn "   '%c': %d" char count)
    
    printfn "\n2. Распределение слов по длинам:"
    wordStats
    |> Map.toSeq 
    |> Seq.sortBy fst 
    |> Seq.iter (fun (length, count) -> 
        printfn "   Длина %d: %d слов" length count)
    
    printfn "\n3. Распределение предложений по количеству слов:"
    sentenceStats
    |> Map.toSeq 
    |> Seq.sortBy fst 
    |> Seq.iter (fun (wordCount, sentenceCount) -> 
        printfn "   %d слов: %d предложений" wordCount sentenceCount)

// Пример использования
let exampleText = """
Hello world! This is a test text. It contains several sentences with different lengths.
Some are short. Others might be longer and more complex. Let's see how the analysis works!
"""

// Запуск анализа
printAnalysis exampleText

// Функция для получения только результатов анализа (без вывода)
let getAnalysisResults (text: string) =
    analyzeText text

// Функции для доступа к отдельным статистикам
let getCharacterStats (text: string) =
    let chars, _, _ = analyzeText text
    chars

let getWordLengthStats (text: string) =
    let _, words, _ = analyzeText text
    words

let getSentenceStats (text: string) =
    let _, _, sentences = analyzeText text
    sentences