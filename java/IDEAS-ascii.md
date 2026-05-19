# Mini-Project Ideas — ASCII Diagrams

Plain ASCII class diagrams for the 4 mini-project ideas. Same content as
`IDEAS.md` but without SVG — works in any plain-text editor.

---

## Idea 1 — Library

A library where you can add, remove and list books and magazines.

```
        ┌──────────────────────┐
        │   <<abstract>>       │
        │   LibraryItem        │
        ├──────────────────────┤
        │ - title: String      │
        │ - year: int          │
        ├──────────────────────┤
        │ + getTitle()/set...  │
        │ + getYear()/set...   │
        │ + describe(): String │ <-- abstract
        └──────────▲───────────┘
                   │ extends
        ┌──────────┴───────────┐
        │                      │
┌───────┴────────┐    ┌────────┴────────┐
│ Book           │    │ Magazine        │
├────────────────┤    ├─────────────────┤
│ - author       │    │ - issueNumber   │
├────────────────┤    ├─────────────────┤
│ + getAuthor()  │    │ + getIssueNo()  │
│ + describe()   │    │ + describe()    │
└────────────────┘    └─────────────────┘

┌────────────────────────────────┐
│ Library                        │
├────────────────────────────────┤
│ - items: ArrayList<LibraryItem>│
├────────────────────────────────┤
│ + addItem(LibraryItem)         │
│ + removeItem(int) throws ...   │
│ + getAllItems()                │
└────────────────────────────────┘

┌────────────────────────────────┐
│ MainApp (JavaFX)               │
│ Buttons: Add Book / Add Magazine / Remove / Show all
└────────────────────────────────┘
```

**Custom exception:** `ItemNotFoundException` when removing an item that doesn't exist.

---

## Idea 2 — Animal Shelter

A shelter where you register dogs and cats and see them in a list.

```
        ┌──────────────────────┐
        │   <<abstract>>       │
        │   Animal             │
        ├──────────────────────┤
        │ - name: String       │
        │ - age: int           │
        ├──────────────────────┤
        │ + getName()/set...   │
        │ + getAge()/set...    │
        │ + makeSound(): String│ <-- abstract
        └──────────▲───────────┘
                   │
        ┌──────────┴───────────┐
        │                      │
┌───────┴────────┐    ┌────────┴────────┐
│ Dog            │    │ Cat             │
├────────────────┤    ├─────────────────┤
│ - breed        │    │ - indoorOnly    │
├────────────────┤    ├─────────────────┤
│ + getBreed()   │    │ + isIndoorOnly()│
│ + makeSound()  │    │ + makeSound()   │
└────────────────┘    └─────────────────┘

┌────────────────────────────────┐
│ Shelter                        │
├────────────────────────────────┤
│ - animals: ArrayList<Animal>   │
├────────────────────────────────┤
│ + addAnimal(Animal)            │
│ + removeAnimal(name) throws... │
│ + listAnimals()                │
└────────────────────────────────┘
```

**Custom exception:** `AnimalNotFoundException`. Good spot for try-catch on input validation (age can't be negative).

---

## Idea 3 — Music Playlist

A playlist that holds songs and albums.

```
        ┌──────────────────────┐
        │   <<abstract>>       │
        │   MusicItem          │
        ├──────────────────────┤
        │ - title: String      │
        │ - artist: String     │
        ├──────────────────────┤
        │ + getters/setters    │
        │ + getDuration(): int │ <-- abstract (minutes)
        └──────────▲───────────┘
                   │
        ┌──────────┴───────────┐
        │                      │
┌───────┴────────┐    ┌────────┴────────┐
│ Song           │    │ Album           │
├────────────────┤    ├─────────────────┤
│ - lengthMin    │    │ - trackCount    │
│                │    │ - avgTrackMin   │
├────────────────┤    ├─────────────────┤
│ + getLength()  │    │ + getTrackCount │
│ + getDuration()│    │ + getDuration() │
└────────────────┘    └─────────────────┘

┌────────────────────────────────┐
│ Playlist                       │
├────────────────────────────────┤
│ - items: ArrayList<MusicItem>  │
├────────────────────────────────┤
│ + add(MusicItem)               │
│ + remove(title) throws ...     │
│ + totalDuration(): int         │
└────────────────────────────────┘
```

**Custom exception:** `ItemNotFoundException` when removing.

---

## Idea 4 — To-do List with Task Types

A simple todo-app with two task types: simple tasks and tasks with a deadline.

```
        ┌──────────────────────┐
        │   <<abstract>>       │
        │   Task               │
        ├──────────────────────┤
        │ - description        │
        │ - done: boolean      │
        ├──────────────────────┤
        │ + getters/setters    │
        │ + summary(): String  │ <-- abstract
        └──────────▲───────────┘
                   │
        ┌──────────┴───────────┐
        │                      │
┌───────┴────────┐    ┌────────┴───────────┐
│ SimpleTask     │    │ DeadlineTask       │
├────────────────┤    ├────────────────────┤
│ (no extras)    │    │ - deadline: String │
├────────────────┤    ├────────────────────┤
│ + summary()    │    │ + getDeadline()    │
│                │    │ + summary()        │
└────────────────┘    └────────────────────┘

┌────────────────────────────────┐
│ TaskList                       │
├────────────────────────────────┤
│ - tasks: ArrayList<Task>       │
├────────────────────────────────┤
│ + addTask(Task)                │
│ + markDone(index) throws...    │
│ + removeTask(index)            │
└────────────────────────────────┘
```

**Custom exception:** `InvalidTaskIndexException`.
