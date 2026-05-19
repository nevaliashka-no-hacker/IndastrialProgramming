Репозиторий для хранения моих работ по предмету 'Промышленное программирование'

Инструкция для pre-commit hook:
cp pre-commit.sh .git/hooks/pre-commit
chmod +x .git/hooks/pre-commit

Команды по исправлению стиля:
clang-format -i *.cpp *.hpp

(для проверки) cppcheck --enable=all
