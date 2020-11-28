#include "list.h"
#include "list_arr.h"

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	char simbol;
	ssize_t len = 0, size_str = 0;
	char *str = NULL, *str_buf = NULL;

	if (stream == NULL)
	{
		*lineptr = NULL;
		*n = 0;
		return -1;
	}
	
	if (((simbol = fgetc(stream)) != '\n') && (simbol != EOF))
	{
		++len;
	}
	else
	{
		*lineptr = NULL;
		*n = 0;
		fgetc(stream);
		return -1;
	}
	
	str = calloc(len * 2, sizeof(char));
	str[0] = simbol;
	size_str = len * 2;
	
	while (((simbol = fgetc(stream)) != '\n') && (simbol != EOF))
	{
		++len;
		
		if (size_str <= len)
		{
			str_buf = realloc(str, sizeof(char) * len * 2);
			size_str = len * 2;
			if (str_buf != NULL)
			{
				str = str_buf;
				str[len - 1] = simbol;
			}
			else
			{
				free(str);
				*lineptr = NULL;
				*n = 0;
				return -1;
			}
		}
		else
		{
			str[len - 1] = simbol;
		}
	}
	
	*n = len;
	str[len] = '\0';
	*lineptr = str;
	
	return len;
}

node_t *readdata(FILE *f)
{
    node_t *film = NULL;
    char *name = NULL;
    char *author = NULL;

    if (!f)
        return NULL;
	
    size_t len = 0;
    if (my_getline(&name, &len, f) != -1 && len != 0)
    {
        len = 0;
        if (my_getline(&author, &len, f) != -1 && len != 0)
        {
            film = listcreatenode(name, author);
        }
        
        free(name);
        free(author);
    }
    
    return film;
}

void freebook(book_r *del)
{
	free(del->author);
	free(del->name);
	free(del);
}

node_t *listonefree(node_t *node)
{
    node_t *tmp = NULL;
        
    if (node)
    {
        tmp = node->next;
        node->next = NULL;
        free(((book_r *)(node->data))->name);
        free(((book_r *)(node->data))->author);
        free(node->data);
        free(node);
        node = NULL;
    }
    return tmp;
}

node_t *listcreatenode(char *name, char *author)
{
    node_t *elem = NULL;
    book_r *book = NULL;
    char *tmp_name = NULL;
    char *tmp_author = NULL;
    
    elem = malloc(sizeof(node_t));
    
    if (elem)
    {
        book = malloc(sizeof(book_r));
        if (book)
        {
            tmp_name = calloc(strlen(name) + 1, sizeof(char));
            if (tmp_name)
            {
                tmp_author = calloc(strlen(author) + 1, sizeof(char));
                if (tmp_author)
                {
                    strncpy(tmp_name, name, strlen(name) + 1);
                    strncpy(tmp_author, author, strlen(author) + 1);
                    
                    book->name = tmp_name;
                    book->author = tmp_author;
                    
                    elem->data = (void *)book;
                    elem->next = NULL;
                }
                else
                {
                    free(book);
                    free(elem);
                    free(tmp_name);
                    elem = NULL;
                }
            }
            else
            {
                free(book);
                free(elem);
                elem = NULL;
            }
        }
        else
        {
            free(elem);
            elem = NULL;
        }
    }
    else
    {
        elem = NULL;
    }
    
    return elem;
}

node_t *listaddbegin(node_t *head, node_t *node)
{
    node->next = head;
    return node;
}
