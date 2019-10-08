file = File.open('kjvdat.txt', 'r')

content = file.read

# parse off ~ line endings.
content.gsub! /\~[\s ]+$/, ''

puts content
