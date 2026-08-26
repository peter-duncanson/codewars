typedef struct node_t Node;

struct node_t
{
    const Node* next;
};

int loop_size(const Node *node);

int main(void)
{
    
    return 0;
}

int loop_size(const Node *node)
{
    size_t array_size = 50000, i = 0;
    const Node **visited = malloc(sizeof(Node *) * array_size);
  
    for (;;)
    {
        for (size_t j = 0; j < i; j++)
            if (visited[j] == node) return i - j;
      
        if (i == array_size)
            visited = realloc(visited, sizeof(Node *) * (array_size += 50000));

        visited[i++] = node;
        node = node->next;
    }
}

typedef struct
{
    const Node **visited;
    size_t count;
} Bucket;

int loop_size(const Node *node)
{
    size_t array_size = 50000, i = 0, key = 0;
    Node *start = node;
    Bucket buckets[10];

    for (size_t n = 0; n < 10; n++)
    {
        buckets[n] = malloc(sizeof(Bucket));
        buckets[n]->visited = malloc(sizeof(Node *) * 10000);
        buckets[n]->count = 0;
    }
   
    for (;;)
    {
        key = node % 10;
        curr_bucket = buckets[key];

        for (Node *p = curr_bucket->visited; p <= curr_bucket->visited + curr_bucket->count; p++)
        {
            if (p == node)
            {
                for (Bucket *bp = buckets; bp < buckets + 10; bp++)
                {
                    i += *bp->count;
                }
                while (start != node)
                {
                    --i;
                    start = start->next;
                }
                return i;
            }
        }

        curr_bucket->visited[curr_bucket->count++] = node;
        node = node->next;

    }
}
