def regroup_chapters(book):
    sorted_book = sorted(book, key=lambda chapter: sum(chapter), reverse=True)

    new_book = []
    current_chapter = []
    current_questions = 0

    for chapter in sorted_book:
        chapter_questions = sum(chapter)

        if current_questions + chapter_questions <= 30:
            current_chapter.extend(chapter)
            current_questions += chapter_questions
        else:
            if current_chapter:
                new_book.append(current_chapter)
            current_chapter = chapter
            current_questions = chapter_questions

    if current_chapter:
        new_book.append(current_chapter)

    return new_book


book = [[1, 2, 3], [20], [2, 4, 8], [1, 1], [15], [11, 2, 4], [40], [1, 2], [1, 3, 2], [48]]
regrouped_book = regroup_chapters(book)

for chapter in regrouped_book:
    print(chapter)