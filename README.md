# Templ

templ is a commandline tool which helps you utilize Templates.

In its basic form, it just copies the contents of a template to your new file.

Basic Usage:
```
templ test.md
```

Templates are stored at ~/Templates

The template is chosen based on its extention.
If multiple templates with the same extension are found, you are given a dialogue to choose which one you want.
If there is only one template, it will be chosen without a dialogue.

## Substitution

Currently there are Two variables which templ can replace

$FILENAME will be replaced with the full filename (i.e. foo.md)

$FILE will only be replaced with the name without the extension (i.e. foo)

Please not that this feature will probably not work with more complicated filetypes (like odt, ods, etc...)

## instalation

clone the repository
```
git clone https://github.com/AderynCrow/templ.git
```

change into the directory
```
cd templ
```

run the install.sh
```
./install.sh
```
